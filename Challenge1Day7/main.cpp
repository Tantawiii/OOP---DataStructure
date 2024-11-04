#include <iostream>
#include <vector>
#include "GeometricShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
using namespace std;
void menu() {
    cout << "\nMenu:\n";
    cout << "1. Calculate Circle Area\n";
    cout << "2. Calculate Triangle Area\n";
    cout << "3. Calculate Rectangle Area\n";
    cout << "4. Calculate Square Area\n";
    cout << "5. Average!\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
void calculateArea(GeometricShape* geometricShape) {
    geometricShape->calculateArea();
}

GeometricShape* createCircle() {
    double radius;
    cout << "Enter radius of the Circle: ";
    cin >> radius;
    return new Circle(radius);
}

GeometricShape* createTriangle() {
    double base, height;
    cout << "Enter base of the Triangle: ";
    cin >> base;
    cout << "Enter height of the Triangle: ";
    cin >> height;
    return new Triangle(base, height);
}

GeometricShape* createRectangle() {
    double width, height;
    cout << "Enter width of the Rectangle: ";
    cin >> width;
    cout << "Enter height of the Rectangle: ";
    cin >> height;
    return new Rectangle(width, height);
}

GeometricShape* createSquare() {
    double side;
    cout << "Enter side length of the Square: ";
    cin >> side;
    return new Square(side);
}

int main() {
    vector<GeometricShape*> shapes;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            shapes.push_back(createCircle());
            break;
        case 2:
            shapes.push_back(createTriangle());
            break;
        case 3:
            shapes.push_back(createRectangle());
            break;
        case 4:
            shapes.push_back(createSquare());
            break;
        case 5: {
            if (shapes.empty()) {
                std::cout << "No shapes to calculate the area.\n";
            }
            else {
                double totalArea = 0.0;
                for (const auto& shape : shapes) {
                    totalArea += shape->calculateArea();
                }
                double averageArea = totalArea / shapes.size();
                std::cout << "Average Area of all shapes: " << averageArea << std::endl;
            }
            break;
        }
        case 6:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}