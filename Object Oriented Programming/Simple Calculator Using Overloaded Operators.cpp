#include <iostream>
using namespace std;

class Number {
public:
    float number;

    void input() {
        cout << "Enter a number: ";
        cin >> number;
    }

    bool operator==(const Number& other) const {
        return number == other.number;
    }

    // Addition operator overload
    Number operator+(const Number& other) const {
        Number result;
        result.number = number + other.number;
        return result;
    }

    // Subtraction operator overload
    Number operator-(const Number& other) const {
        Number result;
        result.number = number - other.number;
        return result;
    }

    // Multiplication operator overload
    Number operator*(const Number& other) const {
        Number result;
        result.number = number * other.number;
        return result;
    }

    // Division operator overload
    Number operator/(const Number& other) const {
        Number result;
        if (other.number != 0) {
            result.number = number / other.number;
        } else {
            cout << "Error: Division by zero!" << endl;
            result.number = 0;  
        }
        return result;
    }

    void display() const {
        cout << "Result: " << number << endl;
    }
};

int main() {
    Number num1, num2, result;
    int choice;

    num1.input();
    num2.input();

    do {
        cout << "\nSimple Calculator Menu:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Check if equal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                result = num1 + num2;
                result.display();
                break;
            case 2:
                result = num1 - num2; 
                result.display();
                break;
            case 3:
                result = num1 * num2; 
                result.display();
                break;
            case 4:
                result = num1 / num2; 
                result.display();
                break;
            case 5:
                if (num1 == num2) {  
                    cout << "The numbers are equal.\n";
                } else {
                    cout << "The numbers are not equal.\n";
                }
                break;
            case 6:
                cout << "Exiting the calculator...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
