#include "Section.h"
#include <iostream>
#include <string>
#include <vector>

Section::Section(string classId) {}

bool Section::isClassIdValid(string classId) {
    bool isValid = true;

    if (classId == this->_classID) {
        isValid = false;
        return isValid;
    }

    return isValid;
}
