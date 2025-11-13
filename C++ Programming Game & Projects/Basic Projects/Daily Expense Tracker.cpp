// Daily Expense Tracker

// Concepts: loops, arrays / vectors, functions, basic totals.

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
 * Simple Expense Tracker
 * ----------------------
 * - Lets the user add expenses with a short note.
 * - Shows the full list of expenses.
 * - Shows the total amount spent.
 */

struct Expense {
    string note;   // What was bought (e.g., "Lunch", "Bus ticket")
    double amount; // How much it cost
};

// Function prototypes
void addExpense(vector<Expense> &expenses);
void showExpenses(const vector<Expense> &expenses);
void showTotal(const vector<Expense> &expenses);

int main() {
    vector<Expense> expenses; // Dynamic list of expenses
    int choice;

    do {
        cout << "\n===== DAILY EXPENSE TRACKER =====\n";
        cout << "1. Add new expense\n";
        cout << "2. Show all expenses\n";
        cout << "3. Show total spent\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Clear leftover newline to safely use getline later
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                showExpenses(expenses);
                break;
            case 3:
                showTotal(expenses);
                break;
            case 4:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

/*
 * addExpense
 * ----------
 * Asks the user for a note and amount, then
 * saves it in the expenses vector.
 */
void addExpense(vector<Expense> &expenses) {
    Expense e;
    cout << "Enter note (e.g., Lunch, Taxi, Movie): ";
    getline(cin, e.note);
    cout << "Enter amount: ";
    cin >> e.amount;

    // Push the new expense at the end of the list
    expenses.push_back(e);

    cout << "✅ Expense added successfully!\n";
    // Clear leftover newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
 * showExpenses
 * ------------
 * Prints all expenses with a serial number.
 */
void showExpenses(const vector<Expense> &expenses) {
    if (expenses.empty()) {
        cout << "No expenses added yet.\n";
        return;
    }

    cout << "\n--- List of Expenses ---\n";
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". " << expenses[i].note
             << " - $" << expenses[i].amount << "\n";
    }
}

/*
 * showTotal
 * ---------
 * Adds all amounts and prints the total money spent.
 */
void showTotal(const vector<Expense> &expenses) {
    double total = 0.0;

    // Sum all expense amounts
    for (const auto &e : expenses) {
        total += e.amount;
    }

    cout << "Total spent today: $" << total << "\n";
}
