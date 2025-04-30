#include <iostream>
using namespace std;

class swimmingPool {
private:
    double length;
    double width;
    double depth;
    double fillRate;
    double drainRate;
    double currentWater;

public:
    swimmingPool() : length(0), width(0), depth(0), fillRate(0), drainRate(0), currentWater(0) {}

    void setInitialValues() {
        cout << "Enter the initial values for the swimming pool:\n";

        // Loop to get valid input for length, width, and depth
        do {
            cout << "Enter length of the pool (in feet): ";
            cin >> length;
            if (length <= 0) {
                cout << "Length must be positive. Please enter again.\n";
            }
        } while (length <= 0);

        do {
            cout << "Enter width of the pool (in feet): ";
            cin >> width;
            if (width <= 0) {
                cout << "Width must be positive. Please enter again.\n";
            }
        } while (width <= 0);

        do {
            cout << "Enter depth of the pool (in feet): ";
            cin >> depth;
            if (depth <= 0) {
                cout << "Depth must be positive. Please enter again.\n";
            }
        } while (depth <= 0);

        // Loop to get valid input for fill rate, drain rate, and current water level
        do {
            cout << "Enter fill rate (gallons per minute): ";
            cin >> fillRate;
            if (fillRate <= 0) {
                cout << "Fill rate must be positive. Please enter again.\n";
            }
        } while (fillRate <= 0);

        do {
            cout << "Enter drain rate (gallons per minute): ";
            cin >> drainRate;
            if (drainRate <= 0) {
                cout << "Drain rate must be positive. Please enter again.\n";
            }
        } while (drainRate <= 0);

        do {
            cout << "Enter current water level (gallons): ";
            cin >> currentWater;
            if (currentWater < 0) {
                cout << "Current water level cannot be negative. Please enter again.\n";
            }
        } while (currentWater < 0);
    }

    double totalCapacity() {
        return length * width * depth * 7.48;  // Convert cubic feet to gallons
    }

    double waterNeeded() {
        return totalCapacity() - currentWater;
    }

    double calculateFillTime() {
        if (fillRate <= 0) {
            cout << "Error: Fill rate must be greater than zero." << endl;
            return -1;
        }
        return waterNeeded() / fillRate;
    }

    double calculateDrainTime() {
        if (drainRate <= 0) {
            cout << "Error: Drain rate must be greater than zero." << endl;
            return -1;
        }
        return currentWater / drainRate;
    }

    void addWater(double minutes) {
        currentWater += fillRate * minutes;
        if (currentWater > totalCapacity()) {
            currentWater = totalCapacity();
        }
    }

    void drainWater(double minutes) {
        currentWater -= drainRate * minutes;
        if (currentWater < 0) {
            currentWater = 0;
        }
    }

    void displayDetails() {
        cout << "Swimming Pool Details:\n";
        cout << "Length: " << length << " feet\n";
        cout << "Width: " << width << " feet\n";
        cout << "Depth: " << depth << " feet\n";
        cout << "Total Capacity: " << totalCapacity() << " gallons\n";
        cout << "Current Water Level: " << currentWater << " gallons\n";
        cout << "Fill Rate: " << fillRate << " gallons/min\n";
        cout << "Drain Rate: " << drainRate << " gallons/min\n";
        cout << "Time to fill completely: " << calculateFillTime() << " minutes\n";
        cout << "Time to drain completely: " << calculateDrainTime() << " minutes\n";
    }
};

int main() {
    swimmingPool pool;

    // Set initial values for the pool through user input
    pool.setInitialValues();

    int choice;
    double minutes;

    do {
        cout << "\nSwimming Pool Management System\n";
        cout << "1. View Pool Details\n";
        cout << "2. Add Water\n";
        cout << "3. Drain Water\n";
        cout << "4. View Time to Fill/Drain\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pool.displayDetails();
                break;
            case 2:
                cout << "Enter minutes to add water: ";
                cin >> minutes;
                pool.addWater(minutes);
                cout << "Added water for " << minutes << " minutes.\n";
                break;
            case 3:
                cout << "Enter minutes to drain water: ";
                cin >> minutes;
                pool.drainWater(minutes);
                cout << "Drained water for " << minutes << " minutes.\n";
                break;
            case 4:
                cout << "Time to fill completely: " << pool.calculateFillTime() << " minutes\n";
                cout << "Time to drain completely: " << pool.calculateDrainTime() << " minutes\n";
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
