#include <iostream>
#include <fstream>
using namespace std;

class FileManager {
private:
    string filename;

public:
    FileManager(const string& fname) : filename(fname) {}

    void readFile() const {
        ifstream input(filename);
        if (!input) {
            cout << "ERROR: Unable to find or open the file!" << endl;
            return;
        }

        cout << "\n--- File Contents ---\n";
        string line;
        bool empty = true;
        while (getline(input, line)) {
            cout << line << endl;
            empty = false;
        }

        if (empty) {
            cout << "[File is empty]" << endl;
        }

        input.close();
    }

    void appendToFile(const string& content) const {
        ofstream output(filename, ios::app);
        if (!output) {
            cerr << "ERROR: Unable to open the file for appending!" << endl;
            return;
        }

        output << content << endl;
        output.close();
        cout << "? Text appended successfully!" << endl;
    }

    void writeToFile(const string& content) const {
        ofstream output(filename);
        if (!output) {
            cerr << "ERROR: Unable to open the file for writing!" << endl;
            return;
        }

        output << content << endl;
        output.close();
        cout << "? File overwritten successfully!" << endl;
    }
};

int main() {
    FileManager file("text.txt");
    int choice;

    do {
        cout << "\n========== FILE HANDLING MENU ==========" << endl;
        cout << "1. Read file contents" << endl;
        cout << "2. Append to file" << endl;
        cout << "3. Overwrite file (write)" << endl;
        cout << "4. Exit program" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                file.readFile();
                break;

            case 2: {
                cout << "Enter the text to append:\n> ";
                string content;
                getline(cin, content);
                file.appendToFile(content);
                file.readFile();
                break;
            }

            case 3: {
                cout << "Enter the new text to write (existing content will be deleted):\n> ";
                string content;
                getline(cin, content);
                file.writeToFile(content);
                file.readFile();
                break;
            }

            case 4:
                cout << " Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
