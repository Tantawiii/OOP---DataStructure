#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Course {
private:
    string courseName;

public:
    Course(string name);

    void displayCourse() const;

    string getCourseName() const;
};

