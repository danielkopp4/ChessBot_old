#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "board.hpp"
#include "location.hpp"
#include "piece.hpp"
#include "move.hpp"

namespace py = pybind11;

PYBIND11_MODULE(chess_lib, m) {
    py::class_<Location>(m, "Location")
        .def(py::init<>())
        .def(py::init<int, int>())
        .def_property("rank", &Location::rank, &Location::set_rank)
        .def_property("file", &Location::file, &Location::set_file)
        .def("string", &Location::string);

    py::class_<Piece, std::shared_ptr<Piece>>(m, "Piece")
    // py::class_<Piece>(m, "Piece")
        .def(py::init<>())
        .def(py::init<int>())
        .def("code", &Piece::code)
        .def("get_name", &Piece::get_name)
        .def("get_char", &Piece::get_char);


    py::class_<Move>(m, "Move")
        .def(py::init<>())
        .def(py::init<Piece, Location, Location>())
        .def("get_san", &Move::get_san)
        .def("get_lan", &Move::get_lan)
        .def("start", &Move::start)
        .def("end", &Move::end)
        .def("__repr__", &Move::get_lan);

    py::class_<Board>(m, "Board")
        .def(py::init<>())
        .def(py::init<const Board&>())
        .def("parse_game", &Board::parse_game)
        .def("start_game", &Board::start_game)
        .def("put_move", &Board::put_move)
        .def("get_legal_moves", &Board::get_legal_moves)
        .def("get_fen", &Board::get_fen)
        .def("get_piece", &Board::get_piece_id)
        .def("get_board", &Board::get_board)
        .def("winner", &Board::winner)
        .def("game_has_ended", &Board::game_has_ended);
        
}