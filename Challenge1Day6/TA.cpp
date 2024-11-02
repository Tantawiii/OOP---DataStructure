#include "TA.h"
TA::TA(string name) : Prof(name) {}

void TA::assist() const {
    cout << getProfessorName() << " is assisting in teaching." << endl;
}