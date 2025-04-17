#ifndef CONNECT4_H
#define CONNECT4_H

#include <vector>
#include <iostream>

class Game {
public:
    enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
    enum Cell { EMPTY, PLAYER1, PLAYER2 };

    Game();

    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    static const int ROWS = 6;
    static const int COLS = 7;

    std::vector<std::vector<Cell>> board;
    bool player1Turn;
    Status gameStatus;
};

#endif // CONNECT4_H
