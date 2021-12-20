#include "board_hash.hpp"

BoardHash::BoardHash(const Consts::board_type& board) {
    int counter = 0;
    int index_counter = 0;
    long long to_put = 0;
    for (int i = 0; i < Consts::rows; i++) {
        for (int j = 0; j < Consts::rows; j++) {
            to_put <<= 4;
            to_put += board[i][j];
            counter += 1;
            if (counter == 4) {
                board_rep_[index_counter] = to_put;
                index_counter += 1;
                to_put = 0;
                counter = 0;
            }
        }
    }
}

Consts::board_type BoardHash::get_board() const {
    Consts::board_type result;
    int counter = 0;
    int index_counter = size_ - 1;
    long long to_put = board_rep_[index_counter];
    for (int i = Consts::rows - 1; i >= 0; i++) {
        for (int j = Consts::rows - 1; j >= 0; j++) {
            result[i][j] = to_put - (to_put >> 4); 
            to_put >>= 4;
            counter += 1;
            if (counter == 4) {
                to_put = board_rep_[index_counter] ;
                index_counter -= 1;
                counter = 0;
            }
        }
    }

    return result;
}

bool BoardHash::operator==(const BoardHash& other) const {
    for (int i = 0; i < size_; i++) {
        if (board_rep_[i] != other.board_rep_[i]) {
            return false;
        }
    }
    return true;
}