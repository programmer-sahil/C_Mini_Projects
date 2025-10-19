#include <stdio.h>

// Function to display each question and return 1 if correct, 0 if wrong
int askQuestion(char question[], char options[][50], char correctOption) {
    char answer;
    printf("\n%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, options[i]);
    }

    printf("Enter your answer (A/B/C/D): ");
    scanf(" %c", &answer);

    if (answer == correctOption || answer == correctOption + 32) { // handle lowercase
        printf("✅ Correct!\n");
        return 1;
    } else {
        printf("❌ Wrong! Correct answer is %c.\n", correctOption);
        return 0;
    }
}

int main() {
    int score = 0;

    printf("===== 🎓 WELCOME TO THE QUIZ GAME 🎓 =====\n");

    // Question 1
    char q1[] = "1️⃣ What is the capital of India?";
    char opt1[4][50] = {"Mumbai", "Delhi", "Kolkata", "Chennai"};
    score += askQuestion(q1, opt1, 'B');

    // Question 2
    char q2[] = "2️⃣ Which language is used for system programming?";
    char opt2[4][50] = {"Python", "C", "HTML", "JavaScript"};
    score += askQuestion(q2, opt2, 'B');

    // Question 3
    char q3[] = "3️⃣ Which planet is known as the Red Planet?";
    char opt3[4][50] = {"Earth", "Venus", "Mars", "Jupiter"};
    score += askQuestion(q3, opt3, 'C');

    // Question 4
    char q4[] = "4️⃣ What does CPU stand for?";
    char opt4[4][50] = {"Central Processing Unit", "Computer Power Unit", "Control Panel Unit", "Central Program Utility"};
    score += askQuestion(q4, opt4, 'A');

    // Question 5
    char q5[] = "5️⃣ Who developed the C programming language?";
    char opt5[4][50] = {"James Gosling", "Guido van Rossum", "Dennis Ritchie", "Bjarne Stroustrup"};
    score += askQuestion(q5, opt5, 'C');

    // Final score
    printf("\n===== 🧾 QUIZ RESULT =====\n");
    printf("Your total score: %d / 5\n", score);

    if (score == 5)
        printf("🎉 Excellent! You're a genius!\n");
    else if (score >= 3)
        printf("👍 Good job! Keep learning.\n");
    else
        printf("📚 Keep practicing and you'll improve!\n");

    return 0;
}
