#include "Teacher.h"
#include <iostream>
#include <string>

using namespace std;

Teacher::Teacher(std::string firstName, std::string lastName, int age, int idNumber) : Person(firstName, lastName, age,
                                                                                              idNumber) {
    _teacherNumber++;
    _distTeacherNumber = _teacherNumber;
}

int Teacher::getTeacherNumber() {
    return _distTeacherNumber;
}

string Teacher::showPersonInformation() {
    string fullName = getFirstName() + " " + getLastName();
    string result = "[Name: " + fullName + "]\n"
                    + "[Age: " + to_string(getAge()) + "]\n"
                    + "[ID Number: " + to_string(getIdNumber()) + "]\n"
                    + "[Teacher Number: " + to_string(getTeacherNumber()) + "]\n";

    return result;
}