#include "location.hpp"
#include "consts.hpp"
#include <array>
#include <cmath>

#ifndef __bit_board_hpp__
#define __bit_board_hpp__

template <int square_size>
class BitBoard {
public:
    BitBoard operator+(const Location& amount) const; // loss of information
    BitBoard operator&(const BitBoard& other) const;
    BitBoard operator|(const BitBoard& other) const;
    BitBoard operator!() const;

    int get(const Location& location) const;
    void set(int value, const Location& location);

    bool operator==(const BitBoard& other) const;
private:
    static const int ll_size = 64; // bits
    static const int len = Consts::bit_board_size*Consts::bit_board_size * square_size / ll_size + 1;
    static const int remainder = Consts::bit_board_size*Consts::bit_board_size * square_size % ll_size;
    typedef std::array<long long, len> bb; // uses short int for each square (2-bits) (-1, 0, 1)
    bb bit_board;    
};

#endif