#include <iostream>
using namespace std;

const int MAX_ORDERS = 10;

class Order {
public:
    int size, flower_type, color;
    double price;

    Order() : size(0), flower_type(0), color(0), price(0.0) {}

    Order(int s, int ft, int c, double p) : size(s), flower_type(ft), color(c), price(p) {}
};

class FloristSystem {
public:
    Order orders[MAX_ORDERS];
    int orderCount;

    // Default constructor
    FloristSystem() : orderCount(0) {}

    void mainMenu() {
        int choice;
        do {
            cout << "\nMain Menu:\n1. Place an Order\n2. View Sales Statistics\n3. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    placeOrder();
                    break;
                case 2:
                    viewStatistics();
                    break;
                case 3:
                    cout << "Exiting the program...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }

    void placeOrder() {
        if (orderCount >= MAX_ORDERS) {
            cout << "Order limit reached. No more orders can be placed.\n";
            return;
        }

        int size = getBouquetSize();
        int flower_type = getFlowerType();
        int color = getFlowerColor();
        double price = calculatePrice(size, flower_type, color);

        orders[orderCount] = Order{size, flower_type, color, price};
        orderCount++;

        cout << "Order placed successfully. Total price: $" << price << endl;
    }

    int getBouquetSize() {
        int size;
        while (true) {
            cout << "\nBouquet size:\n1. Small\n2. Medium\n3. Large\nEnter your choice: ";
            cin >> size;

            if (size >= 1 && size <= 3) { break; } 
            else { cout << "Invalid size. Please try again.\n"; }
        }
        return size;        
    }
    
    int getFlowerType() {
        int flower_type;
        while (true) {
            cout << "\nFlower type:\n1. Rose\n2. Lily\n3. Carnations\n4. Daffodil\n5. Gerbera\n6. Chrysanthemum\n7. Assorted\nEnter your choice: ";
            cin >> flower_type;

            if (flower_type >= 1 && flower_type <= 7) { break; } 
            else { cout << "Invalid flower type. Please try again.\n"; }
        }
        return flower_type;        
    }

    int getFlowerColor() {
        int color;
        while (true) {
            cout << "\nFlower color:\n1. White\n2. Red\n3. Pink\n4. Yellow\n5. Blue\n6. Mixed\nEnter your choice: ";
            cin >> color;

            if (color >= 1 && color <= 6) { break; } 
            else { cout << "Invalid color. Please try again.\n"; }
        }
        return color;        
    }

    double calculatePrice(int size, int flower_type, int color) {
        double sizePrice, flowerPrice, colorPrice;
        
        if (size == 1) sizePrice = 5.5; 
        else if (size == 2) sizePrice = 7.5; 
        else sizePrice = 9.5; 
        
        if (flower_type == 1) flowerPrice = 1.2;
        else if (flower_type == 2) flowerPrice = 1.3;  
        else if (flower_type == 3) flowerPrice = 1.0;  
        else if (flower_type == 4) flowerPrice = 1.0;  
        else if (flower_type == 5) flowerPrice = 1.1;  
        else if (flower_type == 6) flowerPrice = 1.1;  
        else flowerPrice = 0.8; 
        
        if (color == 1) colorPrice = 1.3; 
        else if (color == 2) colorPrice = 1.2;  
        else if (color == 3) colorPrice = 1.1;
        else if (color == 4) colorPrice = 1.1;  
        else if (color == 5) colorPrice = 1.2;  
        else colorPrice = 1.0; 
        
        double price = sizePrice * flowerPrice * colorPrice;
        return price;
    }

    void viewStatistics() {
        if (orderCount == 0) {
            cout << "No orders placed yet.\n";
            return;
        }

        double totalSales = 0.0;
        int totalOrders = orderCount;

        int small = 0, medium = 0, large = 0;
        int white = 0, red = 0, pink = 0, yellow = 0, blue = 0, mixed = 0;
        int rose = 0, lily = 0, carnations = 0, daffodil = 0, gerbera = 0, chrysanthemum = 0, assorted = 0;

        double minPrice = orders[0].price;
        double maxPrice = orders[0].price;

        for (int i = 0; i < orderCount; i++) {
            totalSales += orders[i].price;

            if (orders[i].size == 1) small++;
            else if (orders[i].size == 2) medium++;
            else large++;

            if (orders[i].color == 1) white++;
            else if (orders[i].color == 2) red++;
            else if (orders[i].color == 3) pink++;
            else if (orders[i].color == 4) yellow++;
            else if (orders[i].color == 5) blue++;
            else mixed++;

            if (orders[i].flower_type == 1) rose++;
            else if (orders[i].flower_type == 2) lily++;
            else if (orders[i].flower_type == 3) carnations++;
            else if (orders[i].flower_type == 4) daffodil++;
            else if (orders[i].flower_type == 5) gerbera++;
            else if (orders[i].flower_type == 6) chrysanthemum++;
            else assorted++;
            
            if (orders[i].price < minPrice) minPrice = orders[i].price;
            if (orders[i].price > maxPrice) maxPrice = orders[i].price;
        }

        double averagePrice = (totalOrders > 0) ? (totalSales / totalOrders) : 0;

        cout << "\nSales Statistics:\n";
        cout << "Total Sales: $" << totalSales << endl;
        cout << "Total Orders: " << totalOrders << endl;
        cout << "Average Price: $" << averagePrice << endl;
        cout << "Minimum Price: $" << minPrice << endl;
        cout << "Maximum Price: $" << maxPrice << endl;

        cout << "\nSize Statistics:\n";
        cout << "Small: " << small << endl;
        cout << "Medium: " << medium << endl;
        cout << "Large: " << large << endl;

        cout << "\nColor Statistics:\n";
        cout << "White: " << white << endl;
        cout << "Red: " << red << endl;
        cout << "Pink: " << pink << endl;
        cout << "Yellow: " << yellow << endl;
        cout << "Blue: " << blue << endl;
        cout << "Mixed: " << mixed << endl;

        cout << "\nType Statistics:\n";
        cout << "Rose: " << rose << endl;
        cout << "Lily: " << lily << endl;
        cout << "Carnations: " << carnations << endl;
        cout << "Daffodil: " << daffodil << endl;
        cout << "Gerbera: " << gerbera << endl;
        cout << "Chrysanthemum: " << chrysanthemum << endl;
        cout << "Assorted: " << assorted << endl;
    }
};

int main() {
    FloristSystem system;
    system.mainMenu();
    return 0;
}
