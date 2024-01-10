#include "StudentOperation.h"
#include <iostream>
#include <string>
#include <vector>
#include "../People/Student.h"

using namespace std;

void StudentOperation::AddStudent(vector<Student> &studentsList , vector<int> &studentsNumbers) {
    string firstName;
    cout << "ENTER FIRST NAME: ";
    cin.ignore();
    getline(cin, firstName);

    string lastName;
    cout << "ENTER LAST NAME: ";
    getline(cin, lastName);

    Student student(firstName, lastName);
    studentsList.push_back(student);
    studentsNumbers.push_back(student.getStudentNumber());
}

void StudentOperation::DeleteStudent(vector<Student> &studentsList) {
    cout << "EXIST STUDENTS NUMBERS: \n";
    for (Student student: studentsList) {
        cout << student.getStudentNumber() << endl;
    }
    int number;
    cout << "ENTER YOUR PREFERRED Number --> ";
    cin >> number;
    for (int i = 0; i < studentsList.size(); ++i) {
        if (studentsList[i].getStudentNumber() == number) {
            studentsList.erase(studentsList.begin() + i);
            break;
        }
    }
}

void StudentOperation::EditStudent(vector<Student> &studentsList) {
    int studentNumber;
    for (Student student: studentsList) {
        cout << "[" << student.getFirstName() << "_" << student.getLastName() << " , "
             << student.getStudentNumber() << "]" << endl;
    }
    cout << "ENTER THE NUMBER OF THE STUDENT TO EDIT: ";
    cin >> studentNumber;

    for (Student &student: studentsList) {
        if (student.getStudentNumber() == studentNumber) {
            student.editStudent();
            break;
        }
    }
}

void StudentOperation::ShowStudents(vector<Student> &studentsList) {
    int count = 1;
    for (Student student: studentsList) {
        cout << "  ***" << "\n STUDENT " << count << "\n";
        cout << student.showPersonInformation() << endl;
        count++;
    }
}