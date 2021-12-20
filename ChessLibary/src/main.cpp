#include <string>
#include <iostream>
#include <vector>
#include "move.hpp"
#include "location.hpp"
#include "board.hpp"

void test_main() {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w";// KQkq - 0 1";
    Board b1;
    b1.start_game();
    // std::cout << b1.get_id(0, 1) << std::endl;

    for (int i = 0; i < 7; i++) {
        std::vector<Move> moves = b1.get_legal_moves();
        for (unsigned int i = 0; i < moves.size(); i++) {
            std::cout << i << ": " << moves[i].get_lan() << std::endl;
        }

        int move_index;
        std::cout << "enter the move you want to make: " << std::flush;
        std::cin >> move_index;
        Move m = b1.get_legal_moves()[move_index];
        std::cout << "making " << m.get_lan() << std::endl;
        b1.put_move(m);
        std::cout << "final fen: " << b1.get_fen() << std::endl;
    }

}

void test_piece() {
    Piece p(0);
    std::cout << p.get_char(1) << std::endl;
    std::cout << p.get_char(0) << std::endl;
}

void test_loc() {
    Location l(3, 2);
    std::cout << l.string() << std::endl;
}

void test_move() {
    Location l1(3, 2);
    Location l2(4, 3);
    Piece p(2);
    Move m(p, l1, l2);
    std::cout << m.get_lan() << std::endl;
}


int main() {
    // test_loc();
    test_main();
    // test_move();
    return 0;
}