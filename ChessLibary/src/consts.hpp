#include <memory>
#include <array>
#include "piece.hpp"

#ifndef __consts_hpp__
#define __consts_hpp__

class Consts{
public:
    static const int total_pieces = 16; 
    static const int rows = 8;
    typedef std::shared_ptr<Piece> piece_ptr;
    typedef std::array<std::array<int, rows>, rows> board_type;
    static const int bit_board_size = 2*(rows - 1) + 1;
    static const int small_bb_mult = 2;
    static const int large_bb_mult = 4;
};  

#endif