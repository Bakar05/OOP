#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title, author;
    double price;

    virtual void input() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter price: ";
        while (true) {
            if (cin >> price && price >= 0) {  
                break;
            } else {
                cout << "Invalid input! Please enter a valid positive price: ";
                cin.clear();  
                cin.ignore(1000, '\n');
            }
        }
    }

    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    virtual void displayInfo() const {
        display(); 
    }

    virtual ~Book() = default;  
};

class EBook : public Book {
public:
    double sizeMB;

    void input() override {
        Book::input();
        cout << "Enter file size (MB): ";
        while (true) {
            if (cin >> sizeMB && sizeMB > 0) { 
                break;
            } else {
                cout << "Invalid size! Please enter a valid positive size in MB: ";
                cin.clear();  
                cin.ignore(1000, '\n'); 
            }
        }
    }

    void display() const override {
        Book::display(); 
        cout << "File Size: " << sizeMB << " MB" << endl;
    }

    void displayInfo() const override {
        display();  
    }
};

bool compareBooksByAuthor(Book* book1, Book* book2) {
    return book1->author == book2->author;
}

bool compareBooksByTitle(Book* book1, Book* book2) {
    return book1->title == book2->title;
}

int main() {
    Book* books[100];  
    int numBooks = 0;  
    char choice;

    do {
        cout << "\n1. Add Book\n";
        cout << "2. Add E-Book\n";
        cout << "3. Display Books\n";
        cout << "4. Compare Authors\n";
        cout << "5. Compare Titles\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            if (numBooks < 100) {
                books[numBooks] = new Book();  
                books[numBooks]->input();
                numBooks++;
            } else {
                cout << "Maximum books reached.\n";
            }
            break;
        }

        case '2': {
            if (numBooks < 100) {
                books[numBooks] = new EBook();  
                books[numBooks]->input();
                numBooks++;
            } else {
                cout << "Maximum books reached.\n";
            }
            break;
        }

        case '3': {
            if (numBooks == 0) {
                cout << "No books available.\n";
            } else {
                for (int i = 0; i < numBooks; ++i) {
                    cout << "\nBook " << i + 1 << ":\n";
                    books[i]->displayInfo();
                }
            }
            break;
        }

        case '4': {
            if (numBooks < 2) {
                cout << "At least two books required to compare authors.\n";
                break;
            }

            int index1, index2;
            cout << "Enter index of first book: ";
            cin >> index1;
            cout << "Enter index of second book: ";
            cin >> index2;

            if (index1 >= 1 && index1 <= numBooks && index2 >= 1 && index2 <= numBooks) {
                if (compareBooksByAuthor(books[index1 - 1], books[index2 - 1])) {
                    cout << "Books have the same author.\n";
                } else {
                    cout << "Books have different authors.\n";
                }
            } else {
                cout << "Invalid indices!\n";
            }
            break;
        }

        case '5': {
            if (numBooks < 2) {
                cout << "At least two books required to compare titles.\n";
                break;
            }

            int index1, index2;
            cout << "Enter index of first book: ";
            cin >> index1;
            cout << "Enter index of second book: ";
            cin >> index2;

            if (index1 >= 1 && index1 <= numBooks && index2 >= 1 && index2 <= numBooks) {
                if (compareBooksByTitle(books[index1 - 1], books[index2 - 1])) {
                    cout << "Books have the same title.\n";
                } else {
                    cout << "Books have different titles.\n";
                }
            } else {
                cout << "Invalid indices!\n";
            }
            break;
        }

        case '6':
            cout << "Exiting the program...\n";

            for (int i = 0; i < numBooks; i++) {
                delete books[i];
            }
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != '6');

    return 0;
}
