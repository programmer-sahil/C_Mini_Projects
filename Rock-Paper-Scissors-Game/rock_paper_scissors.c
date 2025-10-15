// Rock-Paper-Scissors Game in C
// Author: SK Sahil
// User vs Computer game using random numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, comp;

    printf("=== Rock Paper Scissors Game ===\n");
    printf("0. Rock\n1. Paper\n2. Scissors\n");
    printf("Enter your choice (0-2): ");
    scanf("%d", &user);

    srand(time(0));  // random seed
    comp = rand() % 3;

    printf("Computer chose: %d\n", comp);

    if (user == comp)
        printf("It's a Draw!\n");
    else if ((user == 0 && comp == 2) || (user == 1 && comp == 0) || (user == 2 && comp == 1))
        printf("You Win! 🎉\n");
    else
        printf("Computer Wins! 💻\n");

    printf("=== Thanks for playing ===\n");
    return 0;
}
