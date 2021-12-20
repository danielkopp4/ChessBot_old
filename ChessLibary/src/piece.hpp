#include <string>
#include <unordered_map>
#include <vector>
#include "location.hpp"
#include "utils.hpp"

#ifndef __piece_hpp__
#define __piece_hpp__


class Piece {
public:
    static std::string piece_indentifiers[]; 
    static std::unordered_map<std::string, int> reversed_identifiers;
    static std::unordered_map<char, int> reversed_identifiers_char;
    static bool identifiers_reversed;
    static const int code_len = 6;

    Piece() : code_(-1) {} 
    Piece(int code) : code_(code) {}
    
    std::string get_name() const;
    int code() const { return code_; }
    char get_character() const; // hack, fix this
    char get_char(int side=1) const;
private:
    int code_;
};

// expensive dont run - for now can take inverse of piece indent
void set_reverse();
Piece parse_piece(std::string& piece_name);
Piece parse_piece(char piece_name);

#endif