#include <string>
#include <sstream>
#include <iostream>
#include "location.hpp"
#include "piece.hpp"

#ifndef __move_hpp__
#define __move_hpp__

class Move {
public:
    Move() {}
    Move(Piece piece, Location start, Location end) : piece_(piece), start_(start), end_(end) {}
    std::string get_san() const; // add support for castling 
    std::string get_lan() const;
    
    Piece get_piece() const { return piece_; }
    void ml_representation() const { return; }// define this, make nof void
    bool out_of_bounds(int bound) const;
    Location start() const { return start_; }
    Location end() const { return end_; }
private:
    Piece piece_;
    Location start_;
    Location end_;
};

#endif