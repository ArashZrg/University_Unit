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

    string _sectionID;
    static vector<string> existingSectionIDs;
    string _sectionName;
    Time time;
    Date date;
    bool isNeedVideoProjector;
    Teacher *_assignedTeacher;
    Location *_assignedLocation;
    vector<int> _studentNumbers;

public:
    Section(string sectionID, string sectionName, bool projector, int startHour, int startMinute, int sectionDuration,
            int examDuration, int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum);

    static bool isSectionIdValid(const string &sectionId);


    [[nodiscard]] string getSectionId() const;

    void assignTeacher(Teacher *teacher);

    void assignLocation(Location *location);

    void addStudentNumber(int studentNumber);

    const vector<int>& getStudentNumbers() const ;
};


#endif