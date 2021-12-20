#include <string>
#include <assert.h>
#include <vector>
#include <cctype>
#include <sstream>
#include <array>
#include <memory>
#include "piece.hpp"
#include "move.hpp"
#include "consts.hpp"
#include "board_hash.hpp"


#ifndef __board_hpp__
#define __board_hpp__

class Board {
public:
    Board(const Board& board);
    ~Board();
    Board& operator=(const Board& board);
    Board() : turn_(0), winner_(0), in_check_(false) { init(); }

    bool puts_in_check(const Move& move, int side) const; // side == 0 for white 1 for black

    int parse_game(std::string& fen);
    void start_game();
    void put_move(const Move& move);
    void pop();

    std::vector<Move> get_legal_moves(bool pseudo_legal=false) const;
    std::string get_fen() const;
    bool game_has_ended() const { return winner_ != 0; }
    int winner() const { return winner_; }

    Consts::piece_ptr get_piece(int id) const;
    Consts::piece_ptr get_piece(Location l) const;
    Consts::piece_ptr get_piece(int rank, int file) const;

    Consts::piece_ptr get_piece_id(int id) const { return get_piece(id); }

    int get_id(int rank, int file) const { return board_[rank][file]; }
    int get_id(Location l) const { return get_id(l.rank(), l.file()); }

    int turn() const { return turn_; }
    int side(int id) const;
    Consts::board_type get_board() const { return board_; }
private:
    void set(const Board& board);
    void init();

    // convert to smart pointers
    std::array<Consts::piece_ptr, Consts::total_pieces+1> white_pieces_; // index 0 is unused, white is <0 
    std::array<Consts::piece_ptr, Consts::total_pieces+1> black_pieces_; // same as above, black is >0

    std::array<Location, Consts::total_pieces+1> white_locations_;
    std::array<Location, Consts::total_pieces+1> black_locations_;

    std::array<bool, Consts::total_pieces+1> white_has_moved_;
    std::array<bool, Consts::total_pieces+1> black_has_moved_;

    int turn_; // 0 is white, 1 is black
    Consts::board_type board_;
    int winner_; // -1 for white win, 0 for neutral, 1 for black 2 for stalemate
    bool in_check_;

    std::unique_ptr<BoardHash> prev_board;
};


int get_id(const Consts::board_type& board, const Location& l, const Move* future_move=nullptr);
void add_legal_moves(const Piece& piece, const Consts::board_type& board, int side, const Location& start, bool has_moved, std::vector<Move>& moves, const Move* future_move=nullptr);
void add_move(const Consts::board_type& board, int side, const Location& end, const Location& start, const Piece& piece, bool& condition, std::vector<Move>& moves, const Move* future_move=nullptr);
void checked_add(const Consts::board_type& board, const Move& move, std::vector<Move>& moves, int side, bool is_pawn=false, bool capturing=false, const Move* future_move=nullptr);
#endif