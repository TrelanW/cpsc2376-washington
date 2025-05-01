#include <iostream>
#include "connect4.h"

int main() {
    Game game;
    int col;

    while (game.status() == Game::State::InProgress) {
        std::cout << "Current Player: " << (game.currentPlayer() == Game::Cell::Red ? "Red" : "Yellow") << "\n";
        std::cout << "Enter column (0-6): ";
        std::cin >> col;
        game.play(col);
    }

    if (game.status() == Game::State::WinRed)
        std::cout << "Red wins!\n";
    else if (game.status() == Game::State::WinYellow)
        std::cout << "Yellow wins!\n";
    else
        std::cout << "It's a draw!\n";

    return 0;
}
