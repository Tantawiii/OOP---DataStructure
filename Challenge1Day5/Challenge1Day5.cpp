#include <iostream>
#include "ComplexNumber.h"
using namespace std;
void menu() {
    cout << "Select an operation:" << endl;
    cout << "1. Add Complex Numbers" << endl;
    cout << "2. Subtract Complex Numbers" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ComplexNumber value1(3.0, 4.0);
    ComplexNumber value2(1.0, 2.0);
    ComplexNumber resultAdd;
    ComplexNumber resultSubtract;
    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Addition: ";
            resultAdd = value1.Add(value2);
            resultAdd.Display();
            break;
        case 2:
            resultSubtract = value2.Subtract(value1);
            cout << "Subtraction: ";
            resultSubtract.Display();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
