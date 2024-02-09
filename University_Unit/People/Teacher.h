#ifndef UNIVERSITY_UNIT_TEACHER_H
#define UNIVERSITY_UNIT_TEACHER_H

#include <iostream>
#include "Person.h"

using namespace std;

class Teacher : public Person {

private:

    static int _teacherNumber;
    int _distTeacherNumber;

public:
    //constructor
    Teacher(string firstName, string lastName);

public:

    string showPersonInformation() override;

public:
    //i wrote this function to edit the Teacher Object
    void editTeacher();

public:
    //to handle the Teacher interference
    // i use this in (Section class)
    bool handleTeacherInterference(Teacher &ob);

public:
    //getter
    [[nodiscard]] int getTeacherNumber() const;

};

#endif

