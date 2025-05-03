#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "connect4.h"

const int CELL_SIZE = 80;
const int SCREEN_WIDTH = 7 * CELL_SIZE;
const int SCREEN_HEIGHT = 6 * CELL_SIZE;

void drawGame(SDL_Renderer* renderer, Game& game, int selectorCol) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // black background
    SDL_RenderClear(renderer);

    game.draw(renderer);

    // Draw selector column
    SDL_Rect highlight = { selectorCol * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &highlight);

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow("Connect 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    Game game;
    
    int selectedCol = 0;
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_ESCAPE: quit = true; break;
                case SDLK_LEFT: selectedCol = std::max(0, selectedCol - 1); break;
                case SDLK_RIGHT: selectedCol = std::min(6, selectedCol + 1); break;
                case SDLK_RETURN:
                    if (game.status() == Game::State::InProgress)
                        game.play(selectedCol);
                    break;
                case SDLK_r: game.reset(); break;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && game.status() == Game::State::InProgress) {
                int col = e.button.x / CELL_SIZE;
                game.play(col);
            }
        }

        drawGame(ren, game, selectedCol);

        // Log winner (for now, no on-screen display)
        if (game.status() != Game::State::InProgress) {
            if (game.status() == Game::State::WinRed)
                std::cout << "Red wins!\n";
            else if (game.status() == Game::State::WinYellow)
                std::cout << "Yellow wins!\n";
            else
                std::cout << "Draw!\n";
        }
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
