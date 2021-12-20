#include "piece.hpp"

std::string Piece::piece_indentifiers[] = {"pawn", "rook", "knight", "bishop", "queen", "king"};
std::unordered_map<std::string, int> Piece::reversed_identifiers;
std::unordered_map<char, int> Piece::reversed_identifiers_char;
bool Piece::identifiers_reversed = false;

std::string Piece::get_name() const {
    return std::string(Piece::piece_indentifiers[code_]);
}

// std::string Piece::get_location_str() const {
//     return location_.string();
// }

void set_reverse() {
    if (Piece::identifiers_reversed) {
        return;
    }

    for (int i = 0; i < Piece::code_len; i++) {
        std::string identifier = Piece::piece_indentifiers[i];
        char character_identifier = identifier[0];

        if (identifier == "knight") {
            character_identifier = 'n';
        }

        Piece::reversed_identifiers.insert({identifier, i});
        Piece::reversed_identifiers_char.insert({character_identifier, i});
    }

    Piece::identifiers_reversed = true;
}

char Piece::get_character() const {
    // std::string name = get_name();
    // if (name == "knight") {
    //     return 'n';
    // }

    if (code_ == 2) {
        return 'n';
    }

    return get_name()[0];
}

char Piece::get_char(int side) const {
    if (side == 0) {
        return get_character() - 32;
    }

    return get_character();
}

Piece parse_piece(std::string& piece_name) {
    set_reverse();
    std::string lower_name = tolower(piece_name);
    int code = Piece::reversed_identifiers[lower_name];
    return Piece(code);
}

Piece parse_piece(char piece_name) {
    set_reverse();
    piece_name = tolower(piece_name);
    int code = Piece::reversed_identifiers_char[piece_name];
    return Piece(code);
}