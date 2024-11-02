#include "Course.h"

Course::Course(string name) : courseName(name) {}

void Course::displayCourse() const {
    cout << "Course: " << courseName << endl;
}

string Course::getCourseName() const {
    return courseName;
}