#include "Student.h"
#include <string>

using namespace std;

Student::Student(string firstName, string lastName) : Person(firstName, lastName) {
    _studentNumber++;
    _distStudentNumber = _studentNumber;

}

string Student::showPersonInformation() {
    string fullName = getFirstName() + " " + getLastName();
    string result = "[Name: " + fullName + "]\n"
                    + "[Student Number : " + to_string(getStudentNumber()) + "]\n";

    return result;
}

int Student::getStudentNumber() const {
    return _distStudentNumber;
}

int Student::_studentNumber = 4023600;