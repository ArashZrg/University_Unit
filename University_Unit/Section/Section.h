#ifndef UNIVERSITY_UNIT_SECTION_H
#define UNIVERSITY_UNIT_SECTION_H

#include <iostream>
#include <string>
#include <vector>
#include "../DateTime/Date.h"
#include "../Location/Location.h"
#include "../People/Person.h"
#include "../People/Student.h"
#include "../People/Teacher.h"
#include "../DateTime/Time.h"

using namespace std;

class Section {
private:
    string _classID;
public:
    Section(string classId);

    bool isClassIdValid(string classId);

};


#endif