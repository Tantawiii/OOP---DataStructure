#include "Prof.h"
Prof::Prof(string name) : professorName(name) {}

void Prof::addCourse(Course* course) {
    courses.push_back(course);
}

void Prof::displayCourses() const {
    cout << professorName << " teaches: ";
    for (const auto& course : courses) {
        cout << course->getCourseName() << " ";
    }
    cout << endl;
}

string Prof::getProfessorName() const { 
    return professorName; 
}