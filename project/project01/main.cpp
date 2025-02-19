#include <iostream>
#include <vector>

enum class Token : char { EMPTY = '.', PLAYER_1 = 'X', PLAYER_2 = 'O'};

const int rows = 6;
const int cols = 7;

//Fuction to create the game board
std::vector<std::vector<Token>> makeBoard() {
	return std::vector<std::vector<Token>>(rows, std::vector<Token>(cols, Token::EMPTY));
}

//Function to display board
void displayBoard(const std::vector<std::vector<Token>>& board) {
	std::cout << std::endl << "  1 2 3 4 5 6 7" << std::endl;
	for (const auto& row : board) {
		std::cout << "| ";
		for (const auto& cell : row) {
			std::cout << static_cast<char>(cell) << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "----------------" << std::endl;
}

int main() {
	std::vector<std::vector<Token>> board = makeBoard();
	displayBoard(board);
	return 0;
}