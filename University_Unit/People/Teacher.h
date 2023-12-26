
#ifndef UNIVERSITY_UNIT_TEACHER_H
#define UNIVERSITY_UNIT_TEACHER_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Teacher : public Person {

private:
    static int _teacherNumber;
    int _distTeacherNumber;

public:
    Teacher(string firstName, string lastName, int age, int idNumber);

    int getTeacherNumber();

    string showPersonInformation();
};

int Teacher::_teacherNumber = 135;


#endif
