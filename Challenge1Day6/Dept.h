#pragma once
#include <iostream>
#include <vector>
#include "Prof.h"
using namespace std;
class Dept {
public:
    string departmentName;
    vector<Prof*> professors;

    Dept(string name);

    void addProfessor(Prof* professor);

    void displayProfessors() const;
};

