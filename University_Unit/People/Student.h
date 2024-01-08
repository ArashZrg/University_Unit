#ifndef UNIVERSITY_UNIT_STUDENT_H
#define UNIVERSITY_UNIT_STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {

private:

    static int _studentNumber;
    int _distStudentNumber;

public:
    //constructor
    Student(string firstName, string lastName);

public:

    string showPersonInformation() override;

public:
    //i wrote this function to edit the Studednt object
    void editStudent();

public:
    //getter

    [[nodiscard]] int getStudentNumber() const;

};

#endif
