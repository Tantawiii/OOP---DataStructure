#include <iostream>
#include "ComplexNumber.h"
using namespace std;

void menu() {
    cout << "Select an operation:" << endl;
    cout << "1. Add Complex Numbers" << endl;
    cout << "2. Subtract Complex Numbers" << endl;
    cout << "3. Set Real and Imaginary Parts" << endl;
    cout << "4. Get Real and Imaginary Parts" << endl;
    cout << "5. Show Object Count" << endl;
    cout << "6. Remove 1 object" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ComplexNumber value0();
    ComplexNumber value1(3.0, 4.0);
    ComplexNumber value2(1.0, 2.0);
    ComplexNumber result;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Addition: ";
            result = value1.Add(value2);
            result.Display();
            break;
        case 2:
            cout << "Subtraction: ";
            result = value1.Subtract(value2);
            result.Display();
            break;
        case 3:
            double real, imag;
            cout << "Enter new real part: ";
            cin >> real;
            cout << "Enter new imaginary part: ";
            cin >> imag;
            value1.setReal(real);
            value1.setImaginary(imag);
            cout << "Updated Complex Number: ";
            value1.Display();
            break;
        case 4:
            cout << "Real part: " << value1.getReal() << endl;
            cout << "Imaginary part: " << value1.getImaginary() << endl;
            break;
        case 5:
            cout << "Current object count: " << ComplexNumber::getObjectCount() << endl;
            break;
        case 6:
            value0().~ComplexNumber();
            cout << "Current object count: " << ComplexNumber::getObjectCount() << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}