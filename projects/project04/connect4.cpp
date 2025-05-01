#include "connect4.h"

Game::Game()
    : board(ROWS, std::vector<Cell>(COLS, Cell::Empty)),
    current(Cell::Red),
    gameState(State::InProgress) {
}

void Game::play(int col) {
    if (gameState != State::InProgress || col < 0 || col >= COLS)
        return;

    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == Cell::Empty) {
            board[row][col] = current;

            if (checkWin(row, col, current)) {
                gameState = (current == Cell::Red) ? State::WinRed : State::WinYellow;
            }
            else {
                bool full = true;
                for (int c = 0; c < COLS; ++c) {
                    if (board[0][c] == Cell::Empty) {
                        full = false;
                        break;
                    }
                }

                gameState = full ? State::Draw : State::InProgress;
                if (gameState == State::InProgress)
                    current = (current == Cell::Red) ? Cell::Yellow : Cell::Red;
            }

            return;
        }
    }
}

Game::State Game::status() const { return gameState; }
void Game::reset() {
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            board[r][c] = Cell::Empty;
    current = Cell::Red;
    gameState = State::InProgress;
}
Game::Cell Game::at(int row, int col) const { return board[row][col]; }
Game::Cell Game::currentPlayer() const { return current; }

bool Game::checkWin(int r, int c, Cell p) const {
    const int directions[4][2] = { {0,1}, {1,0}, {1,1}, {1,-1} };
    for (int i = 0; i < 4; ++i) {
        int dy = directions[i][0], dx = directions[i][1];
        int count = 1;
        for (int d = 1; d < 4; ++d) {
            int y = r + dy * d, x = c + dx * d;
            if (y < 0 || y >= ROWS || x < 0 || x >= COLS || board[y][x] != p) break;
            count++;
        }
        for (int d = 1; d < 4; ++d) {
            int y = r - dy * d, x = c - dx * d;
            if (y < 0 || y >= ROWS || x < 0 || x >= COLS || board[y][x] != p) break;
            count++;
        }
        if (count >= 4) return true;
    }
    return false;
}
