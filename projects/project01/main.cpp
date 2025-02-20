#include <iostream>
#include <vector>

enum class Token : char { EMPTY = '.', PLAYER_1 = 'X', PLAYER_2 = 'O'};
enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW};

//Board dimensions
const int rows = 6;
const int cols = 7;

void printRules() {
	std::cout << std::endl << "\********** Welcome to Connect 4! **********" << std::endl;
	std::cout << "Rules:" << std::endl;
	std::cout << "1. Players take turns dropping their pieces (X or O) into a column." << std::endl;
	std::cout << "2. The piece falls to the lowest empty row in that column." << std::endl;
	std::cout << "3. The first player to connect four of their piece in a row, column, or diagonal wins!" << std::endl;
	std::cout << "4. If the board fills up with no winner, the game is a draw." << std::endl;
	std::cout << "*******************************************" << std::endl;
}

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

bool isValidMove(const std::vector<std::vector<Token>>& board, int col) {
	return col >= 0 && col < cols && board[0][col] == Token::EMPTY;
}

void makeMove(std::vector<std::vector<Token>>& board, int col, Token player) {
	for (int row = rows - 1; row >= 0; --row) {
		if (board[row][col] == Token::EMPTY) {
			board[row][col] = player;
			break;
		}
	}
}

//Function to check for a win or draw
GameState gameStatus(const std::vector<std::vector<Token>>& board) {
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (board[row][col] == Token::EMPTY) continue;
			Token curr = board[row][col];

			//Check right
			if (col + 3 < cols && curr == board[row][col + 1] && curr == board[row][col + 2] && curr == board[row][col + 3])
				return (curr == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

			// Check down
			if (row + 3 < rows && curr == board[row + 1][col] && curr == board[row + 2][col] && curr == board[row + 3][col])
				return (curr == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

			// Check diagonal right-down
			if (row + 3 < rows && col + 3 < cols && curr == board[row + 1][col + 1] && curr == board[row + 2][col + 2] && curr == board[row + 3][col + 3])
				return (curr == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

			// Check diagonal left-down
			if (row + 3 < rows && col - 3 >= 0 && curr == board[row + 1][col - 1] && curr == board[row + 2][col - 2] && curr == board[row + 3][col - 3])
				return (curr == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
		}
	}

// Check for a draw
for (int col = 0; col < cols; ++col) {
	if (board[0][col] == Token::EMPTY) return GameState::ONGOING;
	}
	return GameState::DRAW;
}



int main() {

	printRules();
	std::string choice;

	while (true) {
		std::vector<std::vector<Token>> board = makeBoard();
		displayBoard(board);

		Token currentPlayer = Token::PLAYER_1;
		GameState state = GameState::ONGOING;

		while (state == GameState::ONGOING) {
		int col;
		std::cout << "Player" << (currentPlayer == Token::PLAYER_1 ? "1 (X)" : "2 (O)") << ", enter a column (1-7): ";
		std::cin >> col;
		--col;

		while (std::cin.fail() || !isValidMove(board, col)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid move. Try again: ";
			std::cin >> col;
			--col;
		}
		makeMove(board, col, currentPlayer);
		displayBoard(board);
		state = gameStatus(board);

		if (state == GameState::ONGOING) {
			currentPlayer = (currentPlayer == Token::PLAYER_1 ? Token::PLAYER_2 : Token::PLAYER_1);
		}	
	}
	
		//Announce Results
		if (state == GameState::PLAYER_1_WINS) {
			std::cout << "Player 1 (X) wins!"<< std::endl;
		}
		else if (state == GameState::PLAYER_2_WINS) {
			std::cout << "Player 2 (O) wins!" << std::endl;
		}
		else {
			std::cout << "It's a draw!" << std::endl;
		}

		// Ask for replay
		std::cout << "Play again? (y/n): ";
		std::cin >> choice;

		if (choice != "y" && choice != "Y") {
			break;
		}
	}

	std::cout << "Thanks for playing! Goodbye!" << std::endl;
	return 0;
}