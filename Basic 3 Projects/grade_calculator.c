// Project 2: Student Grade Calculator

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of subjects: ");
    scanf("%d", &n);
    int marks[n];
    int sum = 0;

    for(int i = 0; i < n; i++) {
        printf("Enter marks of subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    float avg = sum / (float)n;
    printf("\nAverage = %.2f\n", avg);

    if(avg >= 90) printf("Grade: A\n");
    else if(avg >= 75) printf("Grade: B\n");
    else if(avg >= 60) printf("Grade: C\n");
    else printf("Grade: D\n");

    return 0;
}
