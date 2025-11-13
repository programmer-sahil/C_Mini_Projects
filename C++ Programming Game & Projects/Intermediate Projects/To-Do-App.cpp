// To-Do List Manager

// Concepts: vectors, menus, remove item, string handling.

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
 * To-Do List Manager
 * ------------------
 * - Add new tasks.
 * - View all tasks.
 * - Mark a task as completed (removes it from the list).
 */

void addTask(vector<string> &tasks);
void viewTasks(const vector<string> &tasks);
void completeTask(vector<string> &tasks);

int main() {
    vector<string> tasks; // Stores all pending tasks
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Complete (remove) task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                cout << "Goodbye! Stay productive.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

/*
 * addTask
 * -------
 * Adds a new task entered by the user.
 */
void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter your task: ";
    getline(cin, task);

    tasks.push_back(task);
    cout << "✅ Task added.\n";
}

/*
 * viewTasks
 * ---------
 * Displays all current tasks with their number.
 */
void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks in your list.\n";
        return;
    }

    cout << "\n--- Your Tasks ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

/*
 * completeTask
 * ------------
 * Removes a task based on the task number.
 */
void completeTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to complete.\n";
        return;
    }

    int num;
    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    cin >> num;

    // Check if the number is valid
    if (num < 1 || num > (int)tasks.size()) {
        cout << "❌ Invalid task number.\n";
        return;
    }

    // Erase the selected task (index is num-1)
    tasks.erase(tasks.begin() + (num - 1));
    cout << "✅ Task completed and removed.\n";
}

