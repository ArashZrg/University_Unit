#include "Teacher.h"
#include <iostream>
#include <string>

using namespace std;

Teacher::Teacher(string firstName, string lastName) : Person(firstName, lastName) {
    _teacherNumber++;
    _distTeacherNumber = _teacherNumber;

}

int Teacher::getTeacherNumber() const {
    return _distTeacherNumber;
}

string Teacher::showPersonInformation() {
    string fullName = getFirstName() + " " + getLastName();
    string result = "[Name: " + fullName + "]\n"
                    + "[Teacher Number: " + to_string(getTeacherNumber()) + "]\n";

    return result;
}


int Teacher::_teacherNumber = 3500;