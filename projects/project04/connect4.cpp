#include "connect4.h"
#include <SDL2/SDL.h>

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

Game::Cell Game::at(int row, int col) const { 
    return board[row][col]; 
}
Game::Cell Game::currentPlayer() const { 
    return current; 
}

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

void Game::draw(SDL_Renderer* renderer) const {
    const int CELL_SIZE = 80;
    SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);  // board background
    SDL_RenderClear(renderer);

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            SDL_Rect cellRect = { col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE };

            Cell cell = board[row][col];
            if (cell != Cell::Empty) {
                SDL_Color color = (cell == Cell::Red)
                    ? SDL_Color{ 255, 0, 0, 255 }
                : SDL_Color{ 255, 255, 0, 255 }; // Yellow
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                SDL_Rect disc = { cellRect.x + 10, cellRect.y + 10, CELL_SIZE - 20, CELL_SIZE - 20 };
                SDL_RenderFillRect(renderer, &disc);
            }
        }
    }
    // Draw black grid lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // black lines
    for (int r = 0; r <= ROWS; ++r) {
        SDL_RenderDrawLine(renderer, 0, r * CELL_SIZE, COLS * CELL_SIZE, r * CELL_SIZE);
    }
    for (int c = 0; c <= COLS; ++c) {
        SDL_RenderDrawLine(renderer, c * CELL_SIZE, 0, c * CELL_SIZE, ROWS * CELL_SIZE);
    }
}
