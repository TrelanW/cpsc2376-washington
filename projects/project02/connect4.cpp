#include "connect4.h"

Game::Game() : board(ROWS, std::vector<Cell>(COLS, EMPTY)), player1Turn(true), gameStatus(ONGOING) {}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (int row = 0; row < Game::ROWS; ++row) {
        for (int col = 0; col < Game::COLS; ++col) {
            char ch = '.';
            if (game.board[row][col] == Game::PLAYER1) ch = 'X';
            else if (game.board[row][col] == Game::PLAYER2) ch = 'O';
            os << ch << ' ';
        }
        os << '\n';
    }
    os << "0 1 2 3 4 5 6\n";
    return os;
}
