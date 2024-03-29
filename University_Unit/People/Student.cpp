#include "Student.h"
#include <string>

using namespace std;

Student::Student(string firstName, string lastName)
        : Person(firstName, lastName) {

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

void Student::editStudent() {
    cout << "CURRENT STUDENT INFORMATION:\n";
    cout << showPersonInformation() << endl;

    string firstName;
    cout << "ENTER NEW FIRST NAME: ";
    cin.ignore();
    getline(cin, firstName);

    string lastName;
    cout << "ENTER NEW LAST NAME: ";
    cin.ignore();
    getline(cin, lastName);

    setFirstName(firstName);
    setLastName(lastName);

    cout << "[*STUDENT UPDATED SUCCESSFULLY!*]\n";
}

int Student::_studentNumber = 4023600;

