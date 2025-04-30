#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    int id;
    string name;
    string grade;
};

void addStudent(const string& filename) {
    ofstream outfile(filename, ios::app); 
    if (!outfile) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    Student student;
    cout << "Enter student ID: ";
    cin >> student.id;
    cin.ignore(); 
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter student grade: ";
    cin >> student.grade;

    outfile << student.id << "," << student.name << "," << student.grade << endl;
    cout << "Student record added successfully." << endl;

    outfile.close();
}

void viewStudents(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    string line;
    cout << "Student Records:" << endl;
    while (getline(infile, line)) {
        int comma1 = line.find(',');
        int comma2 = line.find(',', comma1 + 1);

        int id = stoi(line.substr(0, comma1));
        string name = line.substr(comma1 + 1, comma2 - comma1 - 1);
        string grade = line.substr(comma2 + 1);

        cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << endl;
    }

    infile.close();
}

void searchStudent(const string& filename, int searchID) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        int comma1 = line.find(',');
        int comma2 = line.find(',', comma1 + 1);

        int id = stoi(line.substr(0, comma1));
        string name = line.substr(comma1 + 1, comma2 - comma1 - 1);
        string grade = line.substr(comma2 + 1);

        if (id == searchID) {
            cout << "Student Found:" << endl;
            cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchID << " not found." << endl;
    }

    infile.close();
}

int main() {
    string filename = "students.txt"; 
    char choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent(filename);
                break;
            case '2':
                viewStudents(filename);
                break;
            case '3': {
                int searchID;
                cout << "Enter student ID to search: ";
                cin >> searchID;
                searchStudent(filename, searchID);
                break;
            }
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != '4');

    return 0;
}