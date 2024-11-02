#include <iostream>
#include "ComplexNumber.h"
#include "Uni.h"
#include "TA.h"
#include "Dept.h"
#include "Prof.h"
#include "Course.h"
using namespace std;

void menu() {
    cout << "Select an operation:" << endl;
    cout << "1. Add Complex Numbers" << endl;
    cout << "2. Subtract Complex Numbers" << endl;
    cout << "3. Set Real and Imaginary Parts" << endl;
    cout << "4. Get Real and Imaginary Parts" << endl;
    cout << "5. Show Object Count" << endl;
    cout << "6. Deconstructor Test" << endl;
    cout << "7. Overload Operators and casting operator!" << endl;
    cout << "8. Implementation of the four types of relations & bonus" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ComplexNumber value1(3.0, 4.3);
    ComplexNumber value2(1.0, 2.0);
    ComplexNumber result, result2;
    ComplexNumber newVal(3, 4);
    Course course1("OOP"), course2("Algorithms");
    Prof professor("Tanta");
    Dept department("Game");
    Uni university("ITI");
    TA assistant("Eng. Osama");
    float temp;
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
            cout << "Enter real number: ";
            cin >> real;
            cout << "Enter imaginary number: ";
            cin >> imag;
            value1.setReal(real);
            value1.setImaginary(imag);
            cout << "Updated Complex Number: ";
            value1.Display();
            break;
        case 4:
            cout << "Real: " << value1.getReal() << endl;
            cout << "Imaginary: " << value1.getImaginary() << endl;
            break;
        case 5:
            cout << "Current object count: " << ComplexNumber::getObjectCount() << endl;
            break;
        case 6:
        {
            ComplexNumber value0(value1);
            ComplexNumber val;
            cout << "Current object count: " << ComplexNumber::getObjectCount() << endl;
        }
        cout << "Current object count: " << ComplexNumber::getObjectCount() << endl;
        break;
        case 7:
            result2 = value1 + value2;
            result2.Display();

            result2 = value1 - value2;
            result2.Display();

            result2 = value1 * value2;
            result2.Display();

            result2 = value1 / value2;
            result2.Display();
            cout << "After Casting:" << endl;
            value1 = (int) value1;
            value1.display();

            cout << (value1 == value2 ? (int)true : (int) false) << endl;
            cout << (value1 != value2 ? "Not Equal" : "Equal") << endl;
            break;
        case 8:
            professor.addCourse(&course1);
            professor.addCourse(&course2);
            professor.displayCourses();

            department.addProfessor(&professor);
            department.displayProfessors();

            university.addDepartment(new Dept("Engineering"));
            university.addDepartment(new Dept("Arts"));
            university.displayDepartments();

            assistant.addCourse(&course1);
            assistant.displayCourses();
            assistant.assist();

            cout << "Default Val" << endl;
            newVal.display();

            cout << "Prefix Val" << endl;
            ++newVal;
            newVal.display();

            cout << "Postfix Val" << endl;
            newVal++;
            newVal.display();

            cout << "Prefix Val" << endl;
            --newVal;
            newVal.display();

            cout << "Postfix Val" << endl;
            newVal--;
            newVal.display();

            break;
        case 9:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    } while (choice != 8);

    return 0;
}

