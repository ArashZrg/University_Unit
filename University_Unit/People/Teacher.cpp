#include "Teacher.h"
#include <string>


using namespace std;

Teacher::Teacher(string firstName, string lastName)
        : Person(firstName, lastName) {
    _teacherNumber++;
    _distTeacherNumber = _teacherNumber;

}



string Teacher::showPersonInformation() {
    string result = "[Name: " + getFirstName() + " " + getLastName() + "]\n"
                    + "[Teacher Number: " + to_string(getTeacherNumber()) + "]\n";

    return result;
}

void Teacher::editTeacher() {
    cout << "CURRENT TEACHER INFORMATION:\n";
    cout << showPersonInformation() << endl;

    string firstName;
    cout << "ENTER NEW FIRST NAME: ";
    cin.ignore();
    getline(cin, firstName);

    string lastName;
    cout << "ENTER NEW LAST NAME: ";

    getline(cin, lastName);

    setFirstName(firstName);
    setLastName(lastName);

    cout << "[*TEACHER UPDATED SUCCESSFULLY!*]\n";
}

bool Teacher::handleTeacherInterference(Teacher &ob) {
    bool isValid = true;

    if (getTeacherNumber() == ob.getTeacherNumber()) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

int Teacher::getTeacherNumber() const {
    return _distTeacherNumber;
}

int Teacher::_teacherNumber = 3500;
