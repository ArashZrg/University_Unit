#ifndef UNIVERSITY_UNIT_STUDENT_H
#define UNIVERSITY_UNIT_STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"
#include <vector>

using namespace std;

class Student : public Person {

private:

    static int _studentNumber;
    int _distStudentNumber;

public:
    Student(string firstName, string lastName, int age);

    string showPersonInformation() override;

    int getStudentNumber() const;
};



#endif
