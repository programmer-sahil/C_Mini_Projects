// Temperature Converter in C
// Author: SK Sahil
// Converts between Celsius, Fahrenheit, and Kelvin

#include <stdio.h>

int main() {
    int choice;
    float temp, result;

    printf("=== Temperature Converter ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            result = (temp * 9 / 5) + 32;
            printf("Fahrenheit: %.2f\n", result);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            result = (temp - 32) * 5 / 9;
            printf("Celsius: %.2f\n", result);
            break;

        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            result = temp + 273.15;
            printf("Kelvin: %.2f\n", result);
            break;

        default:
            printf("Invalid choice!\n");
    }

    printf("=== Program by SK Sahil ===\n");
    return 0;
}
