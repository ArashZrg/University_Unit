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
    string _sectionId;
    string _sectionName;
public:
    Section(string sectionId, string sectionName);

    bool isSectionIdValid(string sectionId);

    string getSectionId();

    static vector<string> existingSectionIDs;
};


#endif