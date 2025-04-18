#include <iostream>
#include "connect4.h"

int main() {
    Game game;
    int move;

    while (game.status() == Game::ONGOING) {
        std::cout << game;

        std::cout << "Player " << (game.isPlayer1Turn() ? 1 : 2) << ", enter column (0-6): ";

        if (!(std::cin >> move)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        // Store current turn before playing
        bool beforeTurn = game.isPlayer1Turn();

        // Play the move
        game.play(move);

        // If turn didn’t switch, the move was invalid
        if (game.status() == Game::ONGOING && game.isPlayer1Turn() == beforeTurn) {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    // Game ended — print board one last time
    std::cout << game;

    if (game.status() == Game::PLAYER_1_WINS) {
        std::cout << "Player 1 wins!\n";
    }
    else if (game.status() == Game::PLAYER_2_WINS) {
        std::cout << "Player 2 wins!\n";
    }
    else if (game.status() == Game::DRAW) {
        std::cout << "It's a draw!\n";
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
