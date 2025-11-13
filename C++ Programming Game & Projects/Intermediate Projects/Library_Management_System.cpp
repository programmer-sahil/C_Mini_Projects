// Library Management System (OOP + File I/O)
// Concepts: classes, vector, algorithm, text file save/load, menus, basic search.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

/*
 * Project: Library Management System (Console)
 * -------------------------------------------
 * Features:
 *  - Add books (title, author, year)
 *  - List all books
 *  - Search books by title (substring, case-insensitive)
 *  - Save & load books from a text file (library.txt)
 *
 * Teaching Focus:
 *  - Classes & objects
 *  - std::vector to store objects
 *  - Basic file I/O (ifstream/ofstream)
 */

class Book {
public:
    int id;
    string title;
    string author;
    int year;

    Book() = default;

    Book(int id_, const string& t, const string& a, int y)
        : id(id_), title(t), author(a), year(y) {}
};

class Library {
    vector<Book> books; // All books in memory
    int nextId = 1;     // Auto-incremented ID

public:
    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) {
            // No existing file yet, that's okay
            return;
        }

        books.clear();
        int id, year;
        string title, author;

        // File format: id\n title\n author\n year\n (repeated)
        while (in >> id) {
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(in, title);
            getline(in, author);
            in >> year;
            in.ignore(numeric_limits<streamsize>::max(), '\n');

            books.emplace_back(id, title, author, year);
            nextId = max(nextId, id + 1);
        }
    }

    void saveToFile(const string& filename) const {
        ofstream out(filename);
        for (const auto& b : books) {
            out << b.id << "\n"
                << b.title << "\n"
                << b.author << "\n"
                << b.year << "\n";
        }
    }

    // --- Core operations ---

    void addBook() {
        string title, author;
        int year;

        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter year: ";
        cin >> year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Book b(nextId++, title, author, year);
        books.push_back(b);
        cout << "✅ Book added with ID " << b.id << "\n";
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }

        cout << "\n--- All Books ---\n";
        for (const auto& b : books) {
            cout << "[" << b.id << "] "
                 << b.title << " by " << b.author
                 << " (" << b.year << ")\n";
        }
    }

    void searchByTitle() const {
        if (books.empty()) {
            cout << "No books to search.\n";
            return;
        }

        string query;
        cout << "Enter part of the title to search: ";
        getline(cin, query);

        bool found = false;
        cout << "\nResults:\n";

        for (const auto& b : books) {
            string t = b.title;
            string q = query;

            // Case-insensitive search
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            transform(q.begin(), q.end(), q.begin(), ::tolower);

            if (t.find(q) != string::npos) {
                cout << "[" << b.id << "] "
                     << b.title << " by " << b.author
                     << " (" << b.year << ")\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No matching books found.\n";
        }
    }
};

int main() {
    Library lib;
    const string filename = "library.txt";

    // Load existing books from file (if present)
    lib.loadFromFile(filename);

    int choice;
    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add book\n";
        cout << "2. List all books\n";
        cout << "3. Search by title\n";
        cout << "4. Save & Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: lib.addBook();      break;
            case 2: lib.listBooks();    break;
            case 3: lib.searchByTitle();break;
            case 4:
                lib.saveToFile(filename);
                cout << "Library saved. Goodbye.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
