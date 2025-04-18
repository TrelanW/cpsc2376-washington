#ifndef CONNECT4_H
#define CONNECT4_H

#include <vector>
#include <iostream>

class Game {
public:
    enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
    enum Cell { EMPTY, PLAYER1, PLAYER2 };

    Game();

    void play(int column);
    Status status() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    static const int ROWS = 6;
    static const int COLS = 7;

    std::vector<std::vector<Cell>> board;
    bool player1Turn;
    Status gameStatus;

    bool isValidMove(int col) const;
    int getAvailableRow(int col) const;
    void checkForWin(int row, int col);
    bool isDraw() const;
};

#endif // CONNECT4_H
