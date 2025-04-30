#include <iostream>
using namespace std;

class DroneDeliveryEstimator {
private:
    float BatteryLevel;
    int DeliveryCount;

public:
    DroneDeliveryEstimator() {
        DeliveryCount = 0;
        BatteryLevel = 100;
    }

    void make_delivery(int minute) {
        float BatteryConsumption = 1.5;
        
        if (minute <= 0) {
            cout << "ERROR: Invalid delivery time! Please enter a positive value for delivery time." << endl;
            return;
        }

        float requiredBattery = minute * BatteryConsumption;
        
        if (BatteryLevel >= requiredBattery) {
            BatteryLevel -= requiredBattery;
            DeliveryCount++;
            cout << "Delivery made in " << minute << " minutes. Battery consumed: " << requiredBattery << "%" << endl;
        } else {
            cout << "ERROR. Drone doesn't have enough battery for this delivery." << endl;
        }
    }

    float GetRemainingBattery() const {
        return BatteryLevel;
    }

    int GetCompletedDeliveries() const {
        return DeliveryCount;
    }
};

int main() {
    DroneDeliveryEstimator drone;
    int minute;
    char choice;

    do {
        cout << "Enter time for delivery in minutes: ";
        cin >> minute;

        drone.make_delivery(minute);

        if (drone.GetRemainingBattery() < 1.5) {
            cout << "ERROR. Drone doesn't have enough battery for further deliveries." << endl;
            break;
        }

        cout << "Do you want to make another delivery (y/n)? ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nTotal deliveries completed: " << drone.GetCompletedDeliveries() << "\n";
    cout << "Remaining battery: " << drone.GetRemainingBattery() << "%" << endl;

    return 0;
}
