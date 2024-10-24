#include <iostream>
#include <string.h>
using namespace std;
void reset(int *num) {
    *num = 5;
}
// ============1============
//
//
void timeTableFive(int* five, int five_ = 0) {
    if (five_ > 12) {
        return;
    }

    cout << "5 x " << five_ << " = " << 5 * five_ << endl;
    timeTableFive(five, five_ + 1);
}
// ============1============
// 
// 
// ============2============
// Without Pointers => Factorial & Power
int factWithoutPointer(int num) {
    if (num <= 1)
        return 1;
    return num * factWithoutPointer(num - 1);
}
int powerWithoutPointer(int num, int power = 1) {
    if (power == 0)
        return 1; // Base case: any number to the power of 0 is 1
    else
        return num * powerWithoutPointer(num, power - 1); // Recursive case
}
//
// With Pointers => Factorial & Power
// 
void factWithPointer(int* num) {
    if (*num > 1) {
        int temp = *num - 1;
        factWithPointer(&temp);
        *num *= temp;
    }
}
void powerWithPointer(int* num, int power) {
    if (power == 0) {
        *num = 1;
        return;
    }
    int temp = *num;
    powerWithPointer(num, power - 1); 
    *num *= temp;
}
// ============2============
// 
// 
// ============3============
struct inventoryItems {
    string Name;
    int quantity;
    float value;
};

struct Inventory {
    inventoryItems items[100];
    int itemCount = 0;

    void addItem(std::string itemName, int quantity, float price) {
        if (itemCount < 100) {
            items[itemCount] = { itemName, quantity, price };
            itemCount++;
            cout << "Item added: " << itemName << endl;
        }
        else {
            cout << "Inventory is full!" << endl;
        }
    }

    inventoryItems getItem(int index) {
        if (index >= 0 && index < itemCount) {
            return items[index];
        }
        else {
            cout << "Invalid Slot!" << endl;
            return { "Invalid", 0, 0.0f }; //Another way I found to write all variables in struct with inputs!
        }

    };
};
// ============3============
//
//
    int main() {
        // 1- Prints the time table of 5 using recursion
        int num = 5;
        timeTableFive(&num);
        reset(&num);
        // 2- Use recursion to calculates the factorial and the power of a number with and without pointers
        cout << "Factorial Without Pointer Answer: " << factWithoutPointer(num) << endl;
        cout << "Power Without Pointer Answer: " << powerWithoutPointer(num,5) << endl;
        factWithPointer(&num);
        cout << "Factorial With Pointer Answer: " << num << endl;
        reset(&num);
        powerWithPointer(&num,5);
        cout << "Power With Pointer Answer: " << num << endl;
        // 3- A structure that contains a collection of inventory items, with the number of elements occupying the structure and a function to add and get items out of this structure
        Inventory bag;
        bag.addItem("Sword", 10, 5.99f);
        bag.addItem("Wand", 8, 7.99f);
        inventoryItems item = bag.getItem(1);
        cout << "Retrieved Item: " << item.Name << ", Quantity: " << item.quantity << ", Price: $" << item.value << endl;
        return 0;
    }