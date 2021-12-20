#include <array>
#include "consts.hpp"

#ifndef __board_hash_hpp__
#define __board_hash_hpp__

class Board;
// #include "board.hpp"

class BoardHash {
public:
    BoardHash(const Consts::board_type& board);
    Consts::board_type get_board() const;
    bool operator==(const BoardHash& other) const;

private: // 13 different pieces 2^4 -> 16 4 bits per square
    static const int size_ = 16; // 64 bits -> 4 squares per long long so 16 long longs
    std::array<unsigned long long, size_> board_rep_; 
};

#endif