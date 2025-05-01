#ifndef CONNECT4_H
#define CONNECT4_H

#include <vector>

class Game {
public:
    enum class Cell { Empty, Red, Yellow };
    enum class State { InProgress, Draw, WinRed, WinYellow };

    Game();
    void play(int col);
    State status() const;
    void reset();
    Cell at(int row, int col) const;
    Cell currentPlayer() const;

private:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::vector<std::vector<Cell>> board;
    Cell current;
    State gameState;

    bool checkWin(int lastRow, int lastCol, Cell player) const;
};

#endif
