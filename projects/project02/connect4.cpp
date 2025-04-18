#include "connect4.h"

Game::Game() : board(ROWS, std::vector<Cell>(COLS, EMPTY)), player1Turn(true), gameStatus(ONGOING) {}

void Game::play(int col) {
    if (gameStatus != ONGOING || !isValidMove(col)) return;

    int row = getAvailableRow(col);
    if (row == -1) return;

    board[row][col] = player1Turn ? PLAYER1 : PLAYER2;
    checkForWin(row, col);

    if (gameStatus == ONGOING && isDraw()) {
        gameStatus = DRAW;
    }

    if (gameStatus == ONGOING) {
        player1Turn = !player1Turn;
    }
}

Game::Status Game::status() const {
    return gameStatus;
}

bool Game::isPlayer1Turn() const {
    return player1Turn;
}

bool Game::isValidMove(int col) const {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

int Game::getAvailableRow(int col) const {
    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == EMPTY) return row;
    }
    return -1;
}

void Game::checkForWin(int row, int col) {
    Cell current = board[row][col];

    int directions[4][2] = {
        {0, 1},   // horizontal
        {1, 0},   // vertical
        {1, 1},   // diagonal down-right
        {1, -1}   // diagonal up-right
    };

    for (int i = 0; i < 4; ++i) {
        int dRow = directions[i][0];
        int dCol = directions[i][1];
        int count = 1;

        for (int dir = -1; dir <= 1; dir += 2) {
            int r = row + dir * dRow;
            int c = col + dir * dCol;
            while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == current) {
                ++count;
                r += dir * dRow;
                c += dir * dCol;
            }
        }

        if (count >= 4) {
            gameStatus = (current == PLAYER1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            return;
        }
    }
}

bool Game::isDraw() const {
    for (int col = 0; col < COLS; ++col) {
        if (board[0][col] == EMPTY) return false;
    }
    return true;
}

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
