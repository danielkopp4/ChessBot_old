#include "move.hpp"

std::string Move::get_san() const {
    // add support for captures, castling, promotion, check, checkmate,  
    char piece = piece_.get_char();
    std::string loc = end_.string();
    std::stringstream ss;
    ss << piece << loc;
    return ss.str();
}

std::string Move::get_lan() const {
    std::stringstream ss;
    ss << start_.string() << end_.string();
    return ss.str();
}

bool Move::out_of_bounds(int bound) const {
    return start_.out_of_bounds(bound) or end_.out_of_bounds(bound);
}