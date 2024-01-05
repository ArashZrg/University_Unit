#include "Section.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Section::existingSectionIDs;

Section::Section(string sectionID, string sectionName, bool projector, int startHour, int startMinute,
                 int sectionDuration,
                 int examDuration, int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum) :
        _assignedLocation(nullptr),
        _assignedTeacher(nullptr),
        isNeedVideoProjector(projector),
        time(startHour, startMinute, sectionDuration, examDuration),
        date(year, month, day, examYear, examMonth, examDay, dayNum) {
    if (isSectionIdValid(sectionID)) {
        _sectionID = sectionID;
        existingSectionIDs.push_back(sectionID);
    } else {
        throw invalid_argument("This Section ID Is Already Exist In System ! Please Choose Another ID !");
    }
}


bool Section::isSectionIdValid(const string &sectionId) {
    for (const string &existingId: existingSectionIDs) {
        if (sectionId == existingId) {
            return false;
        }
    }
    return true;
}

string Section::getSectionId() const {
    return _sectionID;
}

void Section::assignTeacher(Teacher *teacher) {
    _assignedTeacher = teacher;
}

void Section::assignLocation(Location *location) {
    _assignedLocation = location;
}

void Section::addStudentNumber(int studentNumber) {
    _studentNumbers.push_back(studentNumber);
}

const vector<int> &Section::getStudentNumbers() const {
    return _studentNumbers;
}
