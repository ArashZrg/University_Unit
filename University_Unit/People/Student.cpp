#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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

    cout << "STUDENT UPDATED SUCCESSFULLY!\n";
}

int Student::_studentNumber = 4023600;

void Student::saveToFile() {
    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << getFirstName() << " , " << getLastName() << "\n";
        file.close();
    } else {
        cerr << "ERROR OPENING FILE FOR SAVING STUDENT DATA.\n";
    }
}

vector<Student> Student::loadFromFile() {
    vector<Student> students;
    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string firstName, lastName;
            getline(ss, firstName, ',');
            getline(ss, lastName);
            students.emplace_back(firstName, lastName);
        }
        file.close();
    } else {
        cerr << "ERROR OPENING FILE FOR LOADING STUDENT DATA.\n";
    }
    return students;
}