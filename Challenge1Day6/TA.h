#pragma once
#include <iostream>
#include <vector>
#include "Prof.h"

class TA : public Prof {
public:
    TA(string name);

    void assist() const;
};