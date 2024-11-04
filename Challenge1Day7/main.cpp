#include <iostream>
#include "GeometricShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
using namespace std;
void menu() {
    cout << "\nMenu:\n";
    cout << "0. Gemoteric Shape!\n";
    cout << "1. Calculate Circle Area\n";
    cout << "2. Calculate Triangle Area\n";
    cout << "3. Calculate Rectangle Area\n";
    cout << "4. Calculate Square Area\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
void calculateArea(GeometricShape* geometricShape) {
    geometricShape->calculateArea();
}
int main() {
    GeometricShape geometricShape;
    Rectangle rectangle;
    Circle circle;
    Square square;
    Triangle triangle;
    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 0:
            calculateArea(&geometricShape);
            break;
        case 1:
            calculateArea(&circle);
            break;
        case 2:
            calculateArea(&triangle);
            break;
        case 3:
            calculateArea(&rectangle);
            break;
        case 4:
            calculateArea(&square);
            break;
        case 5:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}