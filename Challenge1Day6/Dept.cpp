#include "Dept.h"
Dept::Dept(string name) : departmentName(name) {}

void Dept::addProfessor(Prof* professor) {
    professors.push_back(professor);
}

void Dept::displayProfessors() const {
    cout << "Department: " << departmentName << " has professors: ";
    for (const auto& professor : professors) {
        cout << professor->getProfessorName() << " ";
    }
    cout << endl;
}