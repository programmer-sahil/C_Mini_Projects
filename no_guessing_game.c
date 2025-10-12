// Project 3: Number Guessing Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    srand(time(0));  // initialize random
    number = rand() % 100 + 1; // random 1-100

    printf("Guess the number (1 to 100):\n");

    do {
        scanf("%d", &guess);
        attempts++;
        if(guess > number)
            printf("Too high! Try again:\n");
        else if(guess < number)
            printf("Too low! Try again:\n");
        else
            printf("🎉 Correct! You guessed it in %d attempts.\n", attempts);
    } while(guess != number);

    return 0;
}
