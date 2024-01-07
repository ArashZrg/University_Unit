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

//Location &loc: locationsList
void Section::convertIntToStringVector(vector<int> list) {
    for (int l: list) {
        cout << to_string(l) << endl;
    }
}

//void Section::addStudentNumber(int studentNumber) {
//    _studentNumbers.push_back(studentNumber);
//}

//const vector<int> &Section::getStudentNumbers() const {
//    return _studentNumbers;
//}


string Section::showSectionInformation() {

    string result = string(" ID: " + _sectionID + '\n')
                    + string(" NAME: " + _sectionName + '\n')
                    + string(" {TIME} -> " + time.showSectionStartTime() + " , " + time.showSectionDuration() + " , " +
                             time.showSectionFinishTime() + "\n")
                    + string(" {DATE OF START} \n")
                    + string(" --> " + date.showSectionStartDate() + '\n')
                    + string(" {DATE OF EXAM} \n")
                    + string(" --> " + date.showSectionExamDate() + '\n')
                    + string(" VIDEO PROJECTOR: " + convertIntResultToString() + '\n')
                    + string(" STUDENTS LIST: \n")
                    + string(convertIntResultToString())
                    + string(" TEACHER: " + _assignedTeacher->getFirstName() + " " + _assignedTeacher->getLastName());
}

string Section::convertIntResultToString() const {
    if (isNeedVideoProjector) {
        return "TRUE";
    } else {
        return "FALSE";
    }
}

bool Section::firstCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isTimeInterference = time.handleTimeInterference(other.time);

    bool isTeacherInterference = _assignedTeacher && other._assignedTeacher &&
                                 _assignedTeacher->handleTeacherInterference(*(other._assignedTeacher));

    if (isTimeInterference && isTeacherInterference) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

bool Section::secondCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isTimeInterference = time.handleTimeInterference(other.time);
    bool isLocationInterference = _assignedLocation && other._assignedLocation &&
                                  _assignedLocation->handleLocationInterference(*(other._assignedLocation));
    bool isDayInterference = date.handleDayInterference(other.date);

    if (isTimeInterference && isLocationInterference && isDayInterference) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

bool Section::thirdCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isTimeInterference = time.handleTimeInterference(other.time);
    bool isExamDateInterference = date.handleExamDayInterference(other.date);

    if (isTimeInterference && isExamDateInterference) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

bool Section::toCheckTheInterference(Section &other) {
    bool isValid = true;

    if (firstCaseOfInterference(other) || secondCaseOfInterference(other) || thirdCaseOfInterference(other)) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }
}

