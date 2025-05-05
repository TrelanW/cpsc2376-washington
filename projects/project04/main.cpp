#define SDL_MAIN_HANDLED
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "connect4.h"

const int CELL_SIZE = 80;
const int SCREEN_WIDTH = 7 * CELL_SIZE;
const int SCREEN_HEIGHT = 6 * CELL_SIZE + 40;

void drawText(SDL_Renderer* renderer, TTF_Font* font, const std::string& msg, int yOffset = 0) {
    SDL_Color white = { 255, 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(font, msg.c_str(), white);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dst = { (SCREEN_WIDTH - w) / 2, SCREEN_HEIGHT / 2 + yOffset, w, h };
    SDL_RenderCopy(renderer, texture, nullptr, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void runGame(SDL_Renderer* ren, TTF_Font* font) {
    Game game;
    SDL_Event e;
    int selectedCol = 0;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) return;
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_ESCAPE: return;
                case SDLK_LEFT: selectedCol = std::max(0, selectedCol - 1); break;
                case SDLK_RIGHT: selectedCol = std::min(6, selectedCol + 1); break;
                case SDLK_RETURN:
                    if (game.status() == Game::State::InProgress)
                        game.play(selectedCol);
                    break;
                case SDLK_r: game.reset(); break;
                case SDLK_m: return; // back to menu
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && game.status() == Game::State::InProgress) {
                int col = e.button.x / CELL_SIZE;
                game.play(col);
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        game.draw(ren);

        // Draw selector box
        SDL_Rect highlight = { selectedCol * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE };
        SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
        SDL_RenderDrawRect(ren, &highlight);

        // Show result
        if (game.status() == Game::State::WinRed)
            drawText(ren, font, "Red Wins!", 140);
        else if (game.status() == Game::State::WinYellow)
            drawText(ren, font, "Yellow Wins!", 140);
        else if (game.status() == Game::State::Draw)
            drawText(ren, font, "It's a Draw!", 140);

        SDL_RenderPresent(ren);
    }
}

void showMenu(SDL_Renderer* ren, TTF_Font* font) {
    SDL_Event e;
    bool inMenu = true;

    while (inMenu) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) exit(0);
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_RETURN) inMenu = false;
                if (e.key.keysym.sym == SDLK_ESCAPE) exit(0);
            }
        }

        SDL_SetRenderDrawColor(ren, 20, 20, 60, 255);
        SDL_RenderClear(ren);
        drawText(ren, font, "Connect 4", -40);
        drawText(ren, font, "Press Enter to Start", 0);
        drawText(ren, font, "Press Esc to Quit", 40);
        SDL_RenderPresent(ren);
    }
}
int main() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* win = SDL_CreateWindow("Connect 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 20);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return 1;
    }

    while (true) {
        showMenu(ren, font);
        runGame(ren, font);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
