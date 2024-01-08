#include "Teacher.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Teacher::Teacher(string firstName, string lastName) : Person(firstName, lastName) {
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
    cin.ignore();
    getline(cin, lastName);

    setFirstName(firstName);
    setLastName(lastName);

    cout << "TEACHER UPDATED SUCCESSFULLY!\n";
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

void Teacher::saveToFile() {
    ofstream file("teachers.txt", ios::app);
    if (file.is_open()) {
        file << getFirstName() << "," << getLastName() << "\n";
        file.close();
    } else {
        cerr << "ERROR OPENING FILE FOR SAVING TEACHER DATA.\n";
    }
}

vector<Teacher> Teacher::loadFromFile() {
    vector<Teacher> teachers;
    ifstream file("teachers.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string firstName , lastName;
            getline(ss , firstName , ',');
            getline(ss , lastName);
            teachers.emplace_back(firstName , lastName);
        }
        file.close();
    }else{
        cerr << "ERROR OPENING FILE FOR LOADING TEACHERS DATA.\n";
    }
    return teachers;
}