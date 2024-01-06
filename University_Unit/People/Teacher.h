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

    Teacher(string firstName, string lastName);

    int getTeacherNumber() const;

    string showPersonInformation() override;

    void editTeacher();

};

#endif

