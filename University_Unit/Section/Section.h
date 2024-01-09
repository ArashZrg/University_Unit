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
    vector<int> _studentsNumbers;

public:
    //constructor
    Section(string sectionID, string sectionName, bool projector, int startHour, int startMinute, int sectionDuration,
            int examDuration, int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum,
            vector<int> studentNumbers);

private:
    //to validate the valid IDs
    static bool isSectionIdValid(const string &sectionId);

public:

    // to assign Teacher for Section
    void assignTeacher(Teacher *teacher);

    // to assign Location for Section
    void assignLocation(Location *location);

private:

    string studentNumbersList();

public:
    //  This Function Will Show All Information Of Section
    string showSectionInformation();

public:
    //this function is for editing section
//    void editSection();

private:

    // I consider 3 state for interference
    // first one is when we have a same teacher at the same time
    // second state is when we have time and location and day is same
    //third state is when we have same exam time and date

    [[nodiscard]] bool firstCaseOfInterference(Section &other);

    [[nodiscard]] bool secondCaseOfInterference(Section &other);

    [[nodiscard]] bool thirdCaseOfInterference(Section &other);

public:
    // and i use 3 function (first and second and third) in this function
    // and i hope it work right
    [[nodiscard]]bool toCheckTheInterference(Section &other);

    void firstMessage();
    void changeTimeAndTeacher(vector<Teacher> teachersList , Section ob);

    void secondMessage();
    void changeTimeAndLocationAndDate(vector<Location> locationsList , Section ob);

    void thirdMessage();
    void changeExamDate();
private:
    // I Wrote this fucntion to convert projector Result (0 or 1)
    // Into (False or True)
    // And i use this function in the [showSectionInformation()] function.
    [[nodiscard]] string convertIntResultToString() const;

public:
    //getters
    [[nodiscard]] string getSectionId() const;

    [[nodiscard]] string getSectionName() const;

};


#endif