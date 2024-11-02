#pragma once
#include <iostream>
#include <vector>
#include "Dept.h"
class Uni {
private:
    string UniName;
    vector<Dept*> departments;

public:
    Uni(string name);

    ~Uni();

    void addDepartment(Dept* department);

    void displayDepartments() const;
};