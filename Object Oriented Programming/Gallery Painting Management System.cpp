#include <iostream>
#include <string>
using namespace std;

class Painting {
private:
    int paintingID;
    string title;
    int weight;
    static int totalPaintings;
    static int weightCapacity;

public:
    Painting(int p_id, string t, int w) {
        paintingID = p_id;
        title = t;
        weight = w;

        if (weight <= weightCapacity) {
            weightCapacity -= weight;
            totalPaintings++;
            cout << "Painting '" << title << "' added successfully!" << endl;
        } else {
            cout << "Painting '" << title << "' cannot be added! Insufficient wall capacity." << endl;
        }
    }

    static int getTotalPaintings() {
        return totalPaintings;
    }

    static int getWeightCapacity() {
        return weightCapacity;
    }
};

int Painting::totalPaintings = 0;
int Painting::weightCapacity = 10000; 

int main() {
    char choice;
    do {
        int paintingID, weight;
        string paintingTitle;

        cout << "Enter Painting ID: ";
        cin >> paintingID;
        cin.ignore();  
        
        cout << "Enter Painting Title: ";
        getline(cin, paintingTitle);
        
        cout << "Enter Weight of Painting in grams: ";
        cin >> weight;

        while (weight <= 0) {
            cout << "Invalid weight! Please enter a positive value for weight: ";
            cin >> weight;
        }

        Painting painting1(paintingID, paintingTitle, weight);

        cout << "Do you want to add another painting? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nTotal Paintings in Gallery: " << Painting::getTotalPaintings() << endl;
    cout << "Remaining Wall Capacity: " << Painting::getWeightCapacity() << " grams" << endl;

    return 0;
}
