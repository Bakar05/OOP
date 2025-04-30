#include <iostream>
using namespace std;

const int MAX_SLOTS = 10;
const int HOURLY_RATE = 5;

class ParkingSystem {
private:
    string numberPlates[MAX_SLOTS];
    int entryTimes[MAX_SLOTS];  
    bool isOccupied[MAX_SLOTS];
    int totalVehicles;
    double totalRevenue;

public:
    ParkingSystem() {
        for (int i = 0; i < MAX_SLOTS; i++) {
            isOccupied[i] = false;
        }
		totalVehicles = 0;
        totalRevenue = 0.0;
    }

    bool isValidTime(int time) {
        int hours = time / 100;
        int minutes = time % 100;
        return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
    }

    int findSlot(bool findEmpty) {
        for (int i = 0; i < MAX_SLOTS; i++) {
            if (isOccupied[i] == findEmpty)
                return i;
        }
        return -1;
    }

    double calculateFee(int entryTime, int exitTime) {
        int entryHour = entryTime / 100;
        int entryMinute = entryTime % 100;
        int exitHour = exitTime / 100;
        int exitMinute = exitTime % 100;

        int totalEntryMinutes = entryHour * 60 + entryMinute;
        int totalExitMinutes = exitHour * 60 + exitMinute;

        if (totalExitMinutes < totalEntryMinutes) {
            totalExitMinutes += 24 * 60;  
        }

        int durationMinutes = totalExitMinutes - totalEntryMinutes;
        int hoursParked = (durationMinutes + 59) / 60;  

        return hoursParked * HOURLY_RATE;
    }

    void parkVehicle() {
        if (totalVehicles >= MAX_SLOTS) {
            cout << "Parking is full. Cannot park more vehicles.\n";
            return;
        }

        string numberPlate;
        int entryTime;
        
		cout<<"Enter vehicle number plate: ";
        cin>>numberPlate;

        do{
            cout << "Enter entry time (HHMM): ";
            cin >> entryTime;
        } while (!isValidTime(entryTime));

        int slot = findSlot(true);

        if (slot != -1) {
            numberPlates[slot] = numberPlate;
            entryTimes[slot] = entryTime;
            isOccupied[slot] = true;
			totalVehicles++;
            
            cout<<"Vehicle parked in slot "<<slot + 1<<".\n";
        }
    }

    void exitVehicle() {
        string numberPlate;
        int exitTime;
        
        cout<<"Enter vehicle number plate: ";
        cin>>numberPlate;

        int slot = -1;
        for (int i = 0; i < MAX_SLOTS; i++) {
            if (isOccupied[i] && numberPlates[i] == numberPlate) {
                slot = i;
                break;
            }
        }

        if (slot == -1) {
            cout<<"Vehicle not found in the parking lot.\n";
            return;
        }

        do{
            cout<<"Enter exit time (HHMM): ";
            cin>>exitTime;
        }while(!isValidTime(exitTime));

        double fee = calculateFee(entryTimes[slot], exitTime);
        totalRevenue += fee;

        cout<<"Parking fee: $"<<fee<<"\n";
        cout<<"Vehicle exited from slot "<<slot + 1<<".\n";

        isOccupied[slot] = false;
        totalVehicles--;
    }

    void displayParkedVehicles() {
        cout<< "Currently parked vehicles:\n";
        for (int i = 0; i < MAX_SLOTS; i++) {
            if (isOccupied[i]) {
                cout<<"Slot "<<i + 1<<": "<<numberPlates[i]<<", Entry Time: "<<entryTimes[i]<<"\n";
            }
        }
    }

    void showStatistics() {
        cout<<"Total vehicles parked: "<<totalVehicles<<"\n";
        cout<<"Total revenue collected: $"<<totalRevenue<<"\n";
    }
};

int main() {
    ParkingSystem parkingSystem;
    int choice;

    do {
        cout<<"\nParking System Menu:\n";
        cout<<"1. Park a vehicle\n";
        cout<<"2. Exit a vehicle\n";
        cout<<"3. Display currently parked vehicles\n";
        cout<<"4. Show statistics\n";
        cout<<"5. Exit program\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                parkingSystem.parkVehicle();
                break;
            case 2:
                parkingSystem.exitVehicle();
                break;
            case 3:
                parkingSystem.displayParkedVehicles();
                break;
            case 4:
                parkingSystem.showStatistics();
                break;
            case 5:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}