#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() to seed the random number generator
#include <limits>  // Required for input clearing

// Function to handle the main game loop
void playGuessingGame() {
    // Seed the random number generator using the current time
    // This ensures a different sequence of random numbers each time the program runs.
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100 (inclusive)
    const int secretNumber = (std::rand() % 100) + 1;
    int guess = 0;
    int guessCount = 0;
    bool gameWon = false;

    std::cout << "\n--- Welcome to Guess the Number! ---\n";
    std::cout << "I have picked a number between 1 and 100.\n";
    std::cout << "Can you guess it?\n";

    // Main game loop: continues until the user guesses correctly
    while (!gameWon) {
        std::cout << "\nEnter your guess: ";

        // Check if the input is a valid integer
        if (!(std::cin >> guess)) {
            // Handle non-integer input failure
            std::cout << "Invalid input. Please enter a whole number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and ask for input again
        }
        
        // Input validation for range
        if (guess < 1 || guess > 100) {
            std::cout << "That number is out of the 1-100 range. Try again.\n";
            continue;
        }

        // Increment the guess counter
        guessCount++;

        // Conditional logic (if/else if/else) to check the guess
        if (guess == secretNumber) {
            std::cout << "\n*** Congratulations! You guessed the number " << secretNumber 
                      << " in " << guessCount << " tries! ***\n";
            gameWon = true; // Exit the loop
        } else if (guess < secretNumber) {
            std::cout << "Too low! Guess higher.\n";
        } else { // guess > secretNumber
            std::cout << "Too high! Guess lower.\n";
        }
    }
}

int main() {
    char playAgain;
    
    // Outer loop to allow the user to play multiple rounds
    do {
        playGuessingGame();
        
        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> playAgain;
        
        // Clear any lingering input buffer issues
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}
/*
C++ Concepts Covered:
1.  Headers: <iostream>, <cstdlib>, <ctime> for I/O and random numbers.
2.  Functions: The 'playGuessingGame' function encapsulates the core logic.
3.  Randomization: Using srand() and rand() to generate unpredictable output.
4.  Loops: The 'while' loop for the game turns and the 'do-while' loop for replayability.
5.  Conditionals: 'if/else if/else' for giving hints (Too high/low).
6.  Input Validation: Robustly handling non-numeric or out-of-range user input.

How to Compile and Run (using g++ on most systems):

1. Save the code as 'guess_the_number.cpp'.
2. Open your terminal or command prompt.
3. Compile the code:
   g++ -o guesser guess_the_number.cpp
4. Run the executable:
   ./guesser (on Linux/macOS)
   guesser.exe (on Windows)
*/
