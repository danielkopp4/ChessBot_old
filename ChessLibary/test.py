#!/python3
import chess_lib
import chess
import time
# import numpy as np

str_seq = """e2e4
e7e5
d1h5
b8c6
f1c4
g8f6
h5f7"""

seq = [x.strip() for x in str_seq.split("\n")]

def main():
    a = chess_lib.Board()
    a.start_game()
    i = 0
    while not a.game_has_ended():
        display_bard(a)
        moves = a.get_legal_moves(False)
        print("Legal Moves: ")
        for index, move in enumerate(moves):
            print("\t", index, move)

        if i >= len(seq):
            move_index = int(input("which move? "))
        else:
            for index, move in enumerate(moves):
                if repr(move) == seq[i]:
                    move_index = index
                    break
            i += 1
        a.put_move(moves[move_index])

    print("winner: ", a.winner())
    
def display_bard(board):
    board_arr = board.get_board()
    print("+ - - - - - - - - +")
    for i in range(len(board_arr)-1, -1, -1):
        print("| ",end="")
        for j in range(len(board_arr[i])):
            id = board_arr[i][j]
            piece = board.get_piece(id)
            if piece == None:
                print(" ", end="")
            else:
                print(piece.get_char(0 if id < 0 else 1), end="")
            print(" ", end="")
        print("|")
    print("+ - - - - - - - - +")


def volume_test():
    moves = 10000
    i = 0
    prev_time = time.time()
    while i < moves:
        a = chess_lib.Board()
        a.start_game()
        while not a.game_has_ended():
            if i >= moves:
                break

            move = a.get_legal_moves(False)[0]
            a.put_move(move)
            i += 1

    delta = time.time() - prev_time
    print("total time =", delta)
    print("speed:", moves / delta)

def chess_test():
    moves = 10000
    i = 0
    prev_time = time.time()
    while i < moves:
        a = chess.Board()
        while not a.is_game_over():
            if i >= moves:
                break

            move = list(a.legal_moves)[0]
            a.push(move)
            i += 1

    delta = time.time() - prev_time
    print("total time =", delta)
    print("speed:", moves / delta)


if __name__ == "__main__":
    # volume_test()
    chess_test()
    # main()


