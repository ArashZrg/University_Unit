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
    Date date;
    Time time;
    bool isNeedVideoProjector;
public:
    Section(string sectionId, string sectionName, int year, int month, int day, int examYear, int examMonth,
            int examDay, int number, int startHour, int startMinute, int classDuration, int examDuration);

    bool isSectionIdValid(string sectionId);

    string getSectionId();

    static vector<string> existingSectionIDs;
};


#endif