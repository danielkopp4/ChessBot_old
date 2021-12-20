#include "board.hpp"

void Board::set(const Board& board) {
    for (int i = 0; i < Consts::rows; i++) {
        for (int j = 0; j < Consts::rows; j++) {
            board_[i][j] = board.board_[i][j];
        }
    }

    turn_ = board.turn_;

    for (int i = 0; i < Consts::total_pieces; i++) {
        if (board.white_pieces_[i] != nullptr) {
            white_pieces_[i] = std::make_shared<Piece>(*board.white_pieces_[i]);
            white_locations_[i] = board.white_locations_[i];
            white_has_moved_[i] = board.white_has_moved_[i];
        }

        if (board.black_pieces_[i] != nullptr) {
            black_pieces_[i] = std::make_shared<Piece>(*board.black_pieces_[i]);
            black_locations_[i] = board.black_locations_[i];
            black_has_moved_[i] = board.black_has_moved_[i];
        }
    }

    winner_ = board.winner_;
    in_check_ = board.in_check_;
}

void Board::init() {
    // white_pieces_ = new Consts::piece_ptr[Consts::total_pieces+1];
    // black_pieces_ = new Consts::piece_ptr[Consts::total_pieces+1];
    // white_has_moved_ = new bool[Consts::total_pieces+1];
    // black_has_moved_ = new bool[Consts::total_pieces+1];
    for (int i  = 0; i < Consts::total_pieces+1; i++) {
        white_pieces_[i] = nullptr;
        black_pieces_[i] = nullptr;
        white_has_moved_[i] = false;
        black_has_moved_[i] = false;
    }

    // board_ = new int*[Consts::rows];
    for (int i = 0; i < Consts::rows; i++) {
        // board_[i] = new int[Consts::rows];
        for (int j = 0; j < Consts::rows; j++) {
            board_[i][j] = 0;
        }
    }

    // white_locations_ = new Location[Consts::total_pieces+1];
    // black_locations_ = new Location[Consts::total_pieces+1];
}

Board::Board(const Board& board) {
    init();
    set(board);
}

Board::~Board() {
    // for (int i = 0; i < Consts::rows; i++) {
    //     delete board_[i];
    // }
    // delete board_;

    // for (int i = 0; i < Consts::total_pieces; i++) {
    //     if (white_pieces_[i] != nullptr) {
    //         delete white_pieces_[i];
    //     }

    //     if (black_pieces_[i] != nullptr) {
    //         delete black_pieces_[i];
    //     }
    // }

    // delete white_pieces_;
    // delete black_pieces_;
    // delete white_locations_;
    // delete black_locations_;
    // delete white_has_moved_;
    // delete black_has_moved_;
}

Board& Board::operator=(const Board& board) {
    set(board);
    return *this;
}

int Board::parse_game(std::string& fen) {
    int row = Consts::rows-1;
    int col = 0;
    int char_index = 0;
    int white_id = 1;
    int black_id = 1;

    while (true) {
        char character = fen[char_index];
        char_index += 1;

        if (character == ' ') { 
            break;
        }

        if (character == '/') {
            row--;
            col = 0;
            continue;
        }

        if (std::isalpha(character)) {
            Piece piece = parse_piece(character);
            int id = 0;
            
            if (std::isupper(character)) {
                // white 
                white_pieces_[white_id] = std::make_shared<Piece>(piece);
                white_locations_[white_id] = Location(row, col);
                id = -white_id;
                white_id++;
            } else {
                // black
                black_pieces_[black_id] = std::make_shared<Piece>(piece);
                black_locations_[black_id] = Location(row, col);
                id = black_id;
                black_id++;
            }

            board_[row][col] = id;
            col += 1;
        } else {
            // empty
            for (int i = col; i < col + int(character); i++) {
                board_[row][col] = 0;
            }
            col += int(character);
        }

    }

    if (fen[char_index] == 'w') {
        turn_ = 0;
    } else {
        turn_ = 1;
    }

    char_index += 1;
    // check in check
    // check winner

    // castling 
    // en passant
    // half move - less pressing
    // full move - less pressing
    return 0;
}

void Board::start_game() {
    // good enough for now
    std::string starting = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    parse_game(starting);
}

void Board::put_move(const Move& move) {
    // assumes that move is valid - for now
    // if (check_validity) {

    // }

    Location start = move.start();
    Location end = move.end();
    int starting_piece = board_[start.rank()][start.file()];
    
    // remove after properly tested
    // <------------------------------------->
    int code = -1;

    if (starting_piece < 0) {
        code = white_pieces_[-starting_piece]->code();
    } else {
        code = black_pieces_[starting_piece]->code();
    }

    assert(code == move.get_piece().code());
    // <------------------------------------->

    int piece_taken = board_[end.rank()][end.file()];
    if (piece_taken != 0) { // change to use get piece
        // piece is taken
        if (piece_taken < 0) { 
            // piece is white
            // delete white_pieces_[-piece_taken]; // maybe dont delete?
            white_pieces_[-piece_taken] = nullptr;
        } else {
            // piece is black
            // delete black_pieces_[piece_taken];
            black_pieces_[piece_taken] = nullptr;
        }
    }

    board_[end.rank()][end.file()] = board_[start.rank()][start.file()];
    board_[start.rank()][start.file()] = 0;

    if (turn_ == 0) {
        // white
        white_locations_[-starting_piece] = end;
        white_has_moved_[-starting_piece] = true;
    } else {
        // black
        black_locations_[starting_piece] = end;
        black_has_moved_[starting_piece] = true;
    }



    // check for check
    in_check_ = puts_in_check(move, turn_);
    turn_ = (turn_ + 1) % 2;



    int num_legal_moves = get_legal_moves().size();
    
    // check for stalemate
    if (!in_check_ and num_legal_moves == 0) {
        winner_ = 2;
    }

    // check for three fold repetition

    // check for checkmate
    if (in_check_ and num_legal_moves == 0) {
        if (turn_ == 0) {
            // black won || white lost
            winner_ = 1;
        } else {
            // white won || black lost
            winner_ = -1;
        }
    }

}

std::vector<Move> Board::get_legal_moves(bool pseudo_legal) const {
    const std::array<Consts::piece_ptr, Consts::total_pieces+1>* piece_set = nullptr;
    const std::array<Location, Consts::total_pieces+1>* location_set = nullptr;
    const std::array<bool, Consts::total_pieces+1>* has_moved = nullptr;
    int multiplier = 1;

    if (turn_ == 0) {
        // its white's turn 
        piece_set = &white_pieces_;
        location_set = &white_locations_;
        has_moved = &white_has_moved_;
        multiplier = -1;
    } else {
        // its blacks turn
        piece_set = &black_pieces_;
        location_set = &black_locations_;
        has_moved = &black_has_moved_;
    }

    std::vector<Move> moves;
    for (int i = 1; i < Consts::total_pieces+1; i++) {
        if ((*piece_set)[i] != nullptr) {
            // TODO: check possible moves
            int id = i * multiplier;
            const Piece& piece = *get_piece(id);
            add_legal_moves(piece, board_, turn_, (*location_set)[i], (*has_moved)[i], moves);
        }
    }

    if (pseudo_legal) {
        return moves;
    }

    // remove pseudo_legal moves
    for (int i = moves.size() - 1; i >= 0; i--) {
        if (puts_in_check(moves[i], (turn_ + 1) % 2)) {
            moves.erase(moves.begin() + i);
        }
    }


    // dont castle if king would move through check

    return moves;
}


// alternate better method would be to check diagonals, verts, horiz and knight captures centered at the king instead of checking all moves 
bool Board::puts_in_check(const Move& move, int side) const {
    const std::array<Consts::piece_ptr, Consts::total_pieces+1>&  piece_set = (side == 0) ? white_pieces_ : black_pieces_;
    const std::array<Consts::piece_ptr, Consts::total_pieces+1>&  anti_piece_set = (side != 0) ? white_pieces_ : black_pieces_;
    const std::array<Location, Consts::total_pieces+1>& location_set = (side == 0) ? white_locations_ : black_locations_;
    const std::array<Location, Consts::total_pieces+1>& anti_location_set = (side != 0) ? white_locations_ : black_locations_;
    const std::array<bool, Consts::total_pieces+1>&  has_moved_set = (side == 0) ? white_has_moved_ : black_has_moved_;
    int multiplier = (side == 0) ? -1 : 1;
    
    std::vector<Move> new_moves;
    Location king_loc;
    for (int i = 1; i < Consts::total_pieces; i++) {
        if (piece_set[i] != nullptr) {
            int id = multiplier * i;
            bool has_moved = has_moved_set[i];
            Location location = location_set[i];
            if (location == move.start()) {
                location = move.start();
                has_moved = true;
            }
            const Piece& piece = *get_piece(id);
            add_legal_moves(piece, board_, side, location, has_moved, new_moves, &move);
        }

        if (anti_piece_set[i] != nullptr) {
            int id = -multiplier * i;
            Location location = anti_location_set[i];
            const Piece& piece = *get_piece(id);
            if (piece.get_char() == 'k') {
                king_loc = location;
            }
        }
    }


    for (Move new_move : new_moves) {
        if (new_move.end() == king_loc) {
            return true;
        }
    }

    return false;
}

std::string Board::get_fen() const {
    std::stringstream ss;
    for (int i = Consts::rows-1; i >= 0; i--) {
        int counter = 0;
        for (int j = 0; j < Consts::rows; j++) {
            if (board_[i][j] == 0) { 
                counter += 1;
            } else {
                if (counter != 0) {
                    ss << counter;
                    counter = 0;
                }
                int id = board_[i][j];
                ss << get_piece(id)->get_char(side(id));
            }
        }

        if (counter != 0) {
            ss << counter;
        }

        if (i != 0) {
            ss << '/';
        }
    }

    ss << ' ';

    if (turn_ == 0) {
        ss << 'w';
    } else {
        ss << 'b';
    }

    // castling
    // en passant
    // halfmove
    // fullmove

    return ss.str();
}

Consts::piece_ptr Board::get_piece(int id) const {
    if (id == 0) {
        return nullptr;
    }

    const std::array<Consts::piece_ptr, Consts::total_pieces+1>* p = nullptr;
    if (id < 0) {
        p = &white_pieces_;
        id *= -1;
    } else {
        p = &black_pieces_;
    }

    return (*p)[id];
}

int Board::side(int id) const {
    if (id < 0) {
        return 0;
    }

    assert(id != 0);

    return 1;
}

Consts::piece_ptr Board::get_piece(Location l) const {
    return get_piece(l.rank(), l.file());
}

Consts::piece_ptr Board::get_piece(int rank, int file) const {
    return get_piece(get_id(rank, file));
}

int get_id(const Consts::board_type& board, const Location& l, const Move* future_move) {
    if (future_move != nullptr) {
        if (l == future_move->start()) {
            return 0;
        } else if (l == future_move->end()) {
            return get_id(board, future_move->start());
        } 
    }

    return board[l.rank()][l.file()];
}

void add_legal_moves(const Piece& piece, const Consts::board_type& board, int side, const Location& start, bool has_moved, std::vector<Move>& moves, const Move* future_move) {
    char code = piece.get_char();

    if (code == 'p') {
        // add promotions

        if (!has_moved) {
            Location end;
            if (side == 0) {
                end = Location(start.rank() + 2, start.file());
            } else {
                end = Location(start.rank() - 2, start.file());
            }
            Move move(piece, start, end);
            // check valid
            // moves.push_back(move);
            checked_add(board, move, moves, side, true, false, future_move);
        }

        Location end1;
        Location end2;
        Location end3;
        if (side == 0) {
            end1 = Location(start.rank() + 1, start.file());
            end2 = Location(start.rank() + 1, start.file() + 1);
            end3 = Location(start.rank() + 1, start.file() - 1);
        } else {
            end1 = Location(start.rank() - 1, start.file());
            end2 = Location(start.rank() - 1, start.file() + 1);
            end3 = Location(start.rank() - 1, start.file() - 1);
        }

        Move move1(piece, start, end1);
        Move move2(piece, start, end2);
        Move move3(piece, start, end3);
        // check valid
        checked_add(board, move1, moves, side, true, false, future_move);
        checked_add(board, move2, moves, side, true, true, future_move);
        checked_add(board, move3, moves, side, true, true, future_move);    
    }

    if (code == 'r' or code == 'q') {
        bool continue_up = true;
        bool continue_down = true;
        bool continue_left = true;
        bool continue_right = true;

        for (int i = 1; i < Consts::rows; i++) {
            Location end;
            Move move;

            end = Location(start.rank() + i, start.file());
            add_move(board, side, end, start, piece, continue_up, moves, future_move);
            
            end = Location(start.rank() - i, start.file());
            add_move(board, side, end, start, piece, continue_down, moves, future_move);

            end = Location(start.rank(), start.file() + i);
            add_move(board, side, end, start, piece, continue_right, moves, future_move);

            end = Location(start.rank(), start.file() - i);
            add_move(board, side, end, start, piece, continue_left, moves, future_move);
        }
    }

    if (code == 'n') {
        Location end(start.rank() + 2, start.file() + 1);
        Move move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() + 2, start.file() - 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() - 2, start.file() + 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() - 2, start.file() - 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() + 1, start.file() + 2);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() - 1, start.file() + 2);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() + 1, start.file() - 2);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() - 1, start.file() - 2);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);
    }

    if (code == 'b' or code == 'q') {
        bool continue_up = true;
        bool continue_down = true;
        bool continue_left = true;
        bool continue_right = true;

        for (int i = 1; i < Consts::rows; i++) {
            Location end;
            Move move;

            end = Location(start.rank() + i, start.file() + i);
            add_move(board, side, end, start, piece, continue_up, moves, future_move);
            
            end = Location(start.rank() - i, start.file() + i);
            add_move(board, side, end, start, piece, continue_down, moves, future_move);

            end = Location(start.rank() + i, start.file() - i);
            add_move(board, side, end, start, piece, continue_right, moves, future_move);

            end = Location(start.rank() - i, start.file() - i);
            add_move(board, side, end, start, piece, continue_left, moves, future_move);
        }
    }

    if (code == 'k') {
        Location end(start.rank() + 1, start.file());
        Move move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() - 1, start.file());
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank(), start.file() + 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank(), start.file() - 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() + 1, start.file() + 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() + 1, start.file() - 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false,future_move);

        end = Location(start.rank() - 1, start.file() + 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);

        end = Location(start.rank() - 1, start.file() - 1);
        move = Move(piece, start, end);
        checked_add(board, move, moves, side, false, false, future_move);
    }

}

void checked_add(const Consts::board_type& board, const Move& move, std::vector<Move>& moves, int side, bool is_pawn, bool capturing, const Move* future_move) {
    if (move.out_of_bounds(Consts::rows)) {
        return;
    }

    int result = get_id(board, move.end(), future_move);
    
    if (capturing) {
        if (result != 0 and ((result < 0) != (side == 0))) {
            moves.push_back(move);
        }
        return;
    }

    if (is_pawn and result != 0) {
        return;
    }

    if (result != 0 and ((result < 0) == (side == 0))) {
        return;
    }

    moves.push_back(move);
}

void add_move(const Consts::board_type& board, int side, const Location& end, const Location& start, const Piece& piece, bool& condition, std::vector<Move>& moves, const Move* future_move) {
    if (condition) {
        if (end.out_of_bounds(Consts::rows)) {
            condition = false;
        } else {
            int result = get_id(board, end, future_move);

            if (result != 0) {
                condition = false;
                if ((result < 0) != (side == 0)) {
                    Move move(piece, start, end);
                    moves.push_back(move);
                }
            } else {
                Move move(piece, start, end);
                moves.push_back(move);
            }
        }
    }
}