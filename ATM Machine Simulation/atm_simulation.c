#include <stdio.h>

// Concepts used: Functions, Switch, Conditionals, Loops, Float operations

// Function prototypes
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    float balance = 1000.0; // starting balance
    int choice;

    while (1) {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("Thank you for using our ATM! 💳\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to show balance
void checkBalance(float balance) {
    printf("Your current balance is: ₹%.2f\n", balance);
}

// Function to deposit money
float depositMoney(float balance) {
    float deposit;
    printf("Enter amount to deposit: ");
    scanf("%f", &deposit);
    balance += deposit;
    printf("₹%.2f deposited successfully!\n", deposit);
    return balance;
}

// Function to withdraw money
float withdrawMoney(float balance) {
    float withdraw;
    printf("Enter amount to withdraw: ");
    scanf("%f", &withdraw);
    if (withdraw > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance -= withdraw;
        printf("Please collect ₹%.2f\n", withdraw);
    }
    return balance;
}
