#include "bit_board.hpp"

template <int square_size>
BitBoard<square_size> BitBoard<square_size>::operator+(const Location& amount) const {
    if (amount.rank() == 0 && amount.file() == 0) {
        return BitBoard(*this);
    }

    BitBoard result;

    if (amount.rank() != 0) {
        int shift_up = amount.rank();
        int carry_out = 0;
        if (shift_up > 0) {
            for (int i = 0; i < len; i++) {
                int pre_shift = bit_board[i] + carry_out;
                int shifted = pre_shift << (square_size*Consts::bit_board_size*shift_up);
                result.bit_board[i] = shifted % (1 << ll_size);
                carry_out = shifted >> ll_size;
            }
        } else {
            shift_up = -shift_up;
            for (int i = len - 1; i >= 0; i--) {
                int carry_out_len = std::ceil(std::log2(carry_out));
                int pre_shift = bit_board[i] + (carry_out << carry_out_len);
                if (i == len - 1) {
                    pre_shift = pre_shift % (1 >> remainder);
                }

                int shifted = pre_shift >> (square_size*Consts::bit_board_size*shift_up);
                carry_out = shifted % (1 << ll_size);
                result.bit_board[i] = shifted >> ll_size;
            }
        }
    } else {
    }

    if (amount.file() != 0) {
        BitBoard temp;
        temp._is_small = result._is_small;
        for (int i = 0; i < _board_size; i++) {
            if (_is_small) {
                int new_val = _board_size*2
            } else {
                int new_val = 
            }
        }
    }
}