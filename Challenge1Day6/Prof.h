#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Prof {
private:
    string professorName;
    vector<Course*> courses;

public:
    Prof(string name);
    void addCourse(Course* course);
    void displayCourses() const;
    string getProfessorName() const;
};

