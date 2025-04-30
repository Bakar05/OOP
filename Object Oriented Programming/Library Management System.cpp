#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;

class Book {
public:
    string title;
    string author;
    int publication_year;

    Book() {}

    Book(string Title, string Author, int PublicationYear) {
        title = Title;
        author = Author;
        publication_year = PublicationYear;
    }
};

class LibraryBook : public Book {
private:
    int shelf_number;
    bool availability;

public:
    LibraryBook() {}

    LibraryBook(string Title, string Author, int PublicationYear, int ShelfNumber, bool Availability)
        : Book(Title, Author, PublicationYear) {
        shelf_number = ShelfNumber;
        availability = Availability;
    }

    void display_information() const {
        cout << "\n--- Book Information ---\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publication_year << endl;
        cout << "Shelf Number: " << shelf_number << endl;
        cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
    }

    void set_availability(bool isAvailable) {
        availability = isAvailable;
    }

    void check_availability() const {
        cout << "\n--- Availability Status ---\n";
        if (availability) {
            cout << "Book is available.\n";
        } else {
            cout << "Book is currently checked out.\n";
        }
    }
};

int main() {
    LibraryBook books[MAX_BOOKS];
    int book_count = 0;
    char addMore;

    do {
        if (book_count >= MAX_BOOKS) {
            cout << "Maximum number of books reached.\n";
            break;
        }

        string title, author;
        int year, shelf;
        char avail_input;
        bool availability;

        cin.ignore(); // Clear any leftover newline from previous input
        cout << "\nEnter book title: ";
        getline(cin, title);

        cout << "Enter author name: ";
        getline(cin, author);

        cout << "Enter publication year: ";
        cin >> year;

        cout << "Enter shelf number: ";
        cin >> shelf;

        cout << "Is the book available? (y/n): ";
        cin >> avail_input;
        availability = (avail_input == 'y' || avail_input == 'Y');

        books[book_count] = LibraryBook(title, author, year, shelf, availability);
        book_count++;

        cout << "Do you want to add another book? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    for (int i = 0; i < book_count; i++) {
        int choice;
        cout << "\n\n===== MENU FOR BOOK #" << i + 1 << " =====\n";

        do {
            cout << "\n1. Display Book Information";
            cout << "\n2. Check Availability";
            cout << "\n3. Change Availability";
            cout << "\n4. Go to Next Book\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    books[i].display_information();
                    break;

                case 2:
                    books[i].check_availability();
                    break;

                case 3: {
                    char new_avail;
                    cout << "Set availability (y/n): ";
                    cin >> new_avail;
                    books[i].set_availability(new_avail == 'y' || new_avail == 'Y');
                    cout << "Availability updated.\n";
                    break;
                }

                case 4:
                    cout << "Moving to next book...\n";
                    break;

                default:
                    cout << "Invalid choice. Please enter 1-4.\n";
            }
        } while (choice != 4);
    }

    cout << "\nAll books processed. Exiting program.\n";
    return 0;
}
