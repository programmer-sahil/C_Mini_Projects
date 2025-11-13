// Project: Student Gradebook & Ranking

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

/*
 * ------------------------------------
 * Features:
 *  - Add students (ID + name)
 *  - Record multiple marks per student
 *  - Compute average and letter grade
 *  - Show all reports
 *  - Show leaderboard sorted by average marks
 *
 * Teaching Focus:
 *  - Class + encapsulation
 *  - std::map for lookup by ID
 *  - std::vector for variable number of marks
 *  - std::sort with lambda (custom comparator)
 */

class Student {
    string id;
    string name;
    vector<double> marks;

public:
    Student() = default;

    Student(const string& id_, const string& name_)
        : id(id_), name(name_) {}

    const string& getId()   const { return id; }
    const string& getName() const { return name; }

    void addMark(double m) {
        marks.push_back(m);
    }

    double getAverage() const {
        if (marks.empty()) return 0.0;
        double sum = 0.0;
        for (double m : marks) sum += m;
        return sum / marks.size();
    }

    char getGrade() const {
        double avg = getAverage();
        if (avg >= 90) return 'A';
        if (avg >= 75) return 'B';
        if (avg >= 60) return 'C';
        if (avg >= 50) return 'D';
        return 'F';
    }

    void printReport() const {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Average: " << getAverage()
             << ", Grade: " << getGrade()
             << "\n";
    }
};

class Gradebook {
    // key = student ID, value = Student object
    map<string, Student> students;

public:
    void addStudent() {
        string id, name;
        cout << "Enter student ID: ";
        getline(cin, id);
        cout << "Enter student name: ";
        getline(cin, name);

        if (students.find(id) != students.end()) {
            cout << "❌ Student with this ID already exists.\n";
            return;
        }

        students[id] = Student(id, name);
        cout << "✅ Student added.\n";
    }

    void addMarkToStudent() {
        if (students.empty()) {
            cout << "No students yet. Add a student first.\n";
            return;
        }

        string id;
        cout << "Enter student ID: ";
        getline(cin, id);

        auto it = students.find(id);
        if (it == students.end()) {
            cout << "❌ Student not found.\n";
            return;
        }

        double mark;
        cout << "Enter mark (0-100): ";
        cin >> mark;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (mark < 0 || mark > 100) {
            cout << "❌ Invalid mark.\n";
            return;
        }

        it->second.addMark(mark);
        cout << "✅ Mark added to " << it->second.getName() << "\n";
    }

    void showAllReports() const {
        if (students.empty()) {
            cout << "No students in gradebook.\n";
            return;
        }

        cout << "\n--- Student Reports ---\n";
        for (const auto& pair : students) {
            pair.second.printReport();
        }
    }

    void showLeaderboard() const {
        if (students.empty()) {
            cout << "No students in gradebook.\n";
            return;
        }

        // Copy students into a vector for sorting
        vector<Student> list;
        list.reserve(students.size());
        for (const auto& p : students) {
            list.push_back(p.second);
        }

        // Sort students by average marks (descending)
        sort(list.begin(), list.end(),
             [](const Student& a, const Student& b) {
                 return a.getAverage() > b.getAverage();
             });

        cout << "\n=== Leaderboard (by average marks) ===\n";
        int rank = 1;
        for (const auto& s : list) {
            cout << "#" << rank++ << " ";
            s.printReport();
        }
    }
};

int main() {
    Gradebook gb;
    int choice;

    do {
        cout << "\n===== STUDENT GRADEBOOK =====\n";
        cout << "1. Add student\n";
        cout << "2. Add mark to student\n";
        cout << "3. Show all student reports\n";
        cout << "4. Show leaderboard\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: gb.addStudent();       break;
            case 2: gb.addMarkToStudent(); break;
            case 3: gb.showAllReports();   break;
            case 4: gb.showLeaderboard();  break;
            case 5: cout << "Goodbye.\n";  break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
