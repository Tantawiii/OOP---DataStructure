#include "Uni.h"
Uni::Uni(string name) : UniName(name) {}

Uni::~Uni() {
    for (auto dept : departments) {
        delete dept;
    }
}

void Uni::addDepartment(Dept* dept) {
    departments.push_back(dept);
}

void Uni::displayDepartments() const {
    cout << "Uni: " << UniName << " has departments: ";
    for (const auto& dept : departments) {
        cout << dept->departmentName << " ";
    }
    cout << endl;
}