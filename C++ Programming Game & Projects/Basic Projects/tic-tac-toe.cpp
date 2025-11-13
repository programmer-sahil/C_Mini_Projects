#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for input clearing

// Function to draw the Tic-Tac-Toe board
void drawBoard(const std::vector<char>& board) {
    std::cout << "\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    std::cout << "     |     |     \n";
    std::cout << "\n";
}

// Function to check if a player has won
// Returns true if a win condition is met
bool checkWin(const std::vector<char>& board) {
    // Check all 3 rows, 3 columns, and 2 diagonals
    for (int i = 0; i < 3; ++i) {
        // Check rows (i*3, i*3+1, i*3+2)
        if (board[i*3] == board[i*3+1] && board[i*3+1] == board[i*3+2]) {
            return true;
        }
        // Check columns (i, i+3, i+6)
        if (board[i] == board[i+3] && board[i+3] == board[i+6]) {
            return true;
        }
    }

    // Check diagonals
    // Diagonal 1: 0, 4, 8
    if (board[0] == board[4] && board[4] == board[8]) {
        return true;
    }
    // Diagonal 2: 2, 4, 6
    if (board[2] == board[4] && board[4] == board[6]) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        // If any cell still contains a number (1-9), the game is not a draw yet
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true; // All cells are filled, and checkWin returned false
}

// Main game function
int main() {
    std::cout << "Welcome to Console Tic-Tac-Toe!\n";
    std::cout << "Player 1 is X, Player 2 is O. Enter a number (1-9) to make your move.\n";

    // Initialize the board with numbers 1 through 9
    // The numbers represent the available position for the players to choose.
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameOver = false;

    // Main game loop
    while (!gameOver) {
        drawBoard(board);
        int move;

        // Prompt for the current player's move
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";

        // Loop for input validation
        while (!(std::cin >> move) || move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            // Check for non-integer input failure
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a number between 1 and 9: ";
                // Clear the error flags
                std::cin.clear();
                // Ignore the rest of the line from the input buffer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            // Check for out-of-range or already taken position
            else {
                std::cout << "Position " << move << " is already taken or invalid. Choose another position (1-9): ";
            }
        }
        
        // Apply the move to the board (adjusting from 1-based input to 0-based index)
        board[move - 1] = currentPlayer;

        // 1. Check for a win
        if (checkWin(board)) {
            drawBoard(board);
            std::cout << "Game Over! Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } 
        // 2. Check for a draw
        else if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "Game Over! It's a draw!\n";
            gameOver = true;
        } 
        // 3. Switch player if the game continues
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

/*
How to Compile and Run (using g++ on most systems):

1. Save the code as 'tic_tac_toe.cpp'.
2. Open your terminal or command prompt.
3. Compile the code:
   g++ -o tictactoe tic_tac_toe.cpp -std=c++11
4. Run the executable:
   ./tictactoe (on Linux/macOS)
   tictactoe.exe (on Windows)
*/
