// Simple Contact Book (Using Class)
// Concepts: classes/objects, vectors of objects, basic CRUD operations.

#include <iostream>
#include <vector>
#include <string>
#include <limits>   // <-- REQUIRED for numeric_limits
using namespace std;


/*
 * Contact Book
 * ------------
 * - Stores name and phone number.
 * - Add new contacts.
 * - View all contacts.
 * - Search contact by name.
 */

class Contact {
public:
    string name;
    string phone;

    // Constructor to quickly create a contact
    Contact(string n, string p) {
        name = n;
        phone = p;
    }
};

void addContact(vector<Contact> &contacts);
void viewContacts(const vector<Contact> &contacts);
void searchContact(const vector<Contact> &contacts);

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n===== CONTACT BOOK =====\n";
        cout << "1. Add contact\n";
        cout << "2. View all contacts\n";
        cout << "3. Search contact by name\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                cout << "Closing contact book.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}

/*
 * addContact
 * ----------
 * Takes input from user and pushes a new Contact object into the vector.
 */
void addContact(vector<Contact> &contacts) {
    string name, phone;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone: ";
    getline(cin, phone);

    Contact c(name, phone);
    contacts.push_back(c);

    cout << "✅ Contact saved.\n";
}

/*
 * viewContacts
 * ------------
 * Prints all stored contacts.
 */
void viewContacts(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts stored.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].name
             << " - " << contacts[i].phone << "\n";
    }
}

/*
 * searchContact
 * -------------
 * Asks for a name and prints all contacts that match (case-sensitive).
 */
void searchContact(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts to search.\n";
        return;
    }

    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto &c : contacts) {
        if (c.name == searchName) {
            cout << "Found: " << c.name << " - " << c.phone << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No contact found with that exact name.\n";
}
