//
// Created by Arash on 1/10/2024.
//

#include "TeacherOperation.h"
#include "../People/Teacher.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void TeacherOperation::AddTeacher(vector<Teacher> &teachersList) {
    string firstName;
    cout << " ENTER FIRST NAME: ";
    cin.ignore();
    getline(cin, firstName);

    string lastName;
    cout << "ENTER LAST NAME: ";
    getline(cin, lastName);

    Teacher teacher(firstName, lastName);
    teachersList.push_back(teacher);
}


void TeacherOperation::DeleteTeacher(vector<Teacher> &teachersList) {
    cout << "ID OF EXIST TEACHERS : \n";
    for (Teacher tech: teachersList) {
        cout << "[" << tech.getFirstName() << "_" << tech.getLastName() << " , "
             << tech.getTeacherNumber() << "]" << endl;
    }
    int number;
    cout << "ENTER YOUR PREFERRED ID --> ";
    cin >> number;
    for (int i = 0; i < teachersList.size(); ++i) {
        if (teachersList[i].getTeacherNumber() == number) {
            teachersList.erase(teachersList.begin() + i);
            break;
        }
    }
}

void TeacherOperation::EditTeacher(vector<Teacher> &teachersList) {

    int teacherNumber;
    for (Teacher tech: teachersList) {
        cout << "[" << tech.getFirstName() << "_" << tech.getLastName() << " , "
             << tech.getTeacherNumber() << "]" << endl;
    }
    cout << "ENTER THE NUMBER OF THE TEACHER TO EDIT: ";
    cin >> teacherNumber;

    for (Teacher &tech: teachersList) {
        if (tech.getTeacherNumber() == teacherNumber) {
            tech.editTeacher();
            break;
        }
    }
}

void TeacherOperation::ShowTeacher(vector<Teacher> &teachersList) {
    int count = 1;
    for (Teacher tech: teachersList) {
        cout << "  ***" << "\n TEACHER " << count << "\n";
        cout << tech.showPersonInformation() << endl;
        count++;
    }
}