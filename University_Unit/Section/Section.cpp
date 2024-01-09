#include "Section.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> Section::existingSectionIDs;

Section::Section(string sectionID, string sectionName, bool projector, int startHour, int startMinute,
                 int sectionDuration,
                 int examDuration, int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum,
                 vector<int> studentNumbers) :
        _sectionName(sectionName),
        _studentsNumbers(studentNumbers),
        _assignedLocation(nullptr),
        _assignedTeacher(nullptr),
        isNeedVideoProjector(projector),
        time(startHour, startMinute, sectionDuration, examDuration),
        date(year, month, day, examYear, examMonth, examDay, dayNum) {
    if (isSectionIdValid(sectionID)) {
        _sectionID = sectionID;
        existingSectionIDs.push_back(sectionID);
    } else {
        throw invalid_argument("This Section ID Is Already Exist In System !");
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
                    + string(studentNumbersList())
                    + string(" TEACHER: " + _assignedTeacher->getFirstName() + " " + _assignedTeacher->getLastName());
    return result;
}

string Section::studentNumbersList() {
    string result;
    for (int s: _studentsNumbers) {
        result += string(to_string(s) + '\n');
    }
    return result;
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

    if (!(isTimeInterference && isTeacherInterference)) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

void Section::firstMessage() {
    cout << "CHOOSE ANOTHER TIME AND ANOTHER TEACHER!";
}

void Section::changeTimeAndTeacher(vector<Teacher> teachersList, Section ob) {
    cout << "[CURRENT SECTION INFORMATION]\n";
    cout << showSectionInformation() << endl;

    int startHour;
    int startMinute;
    cout << " [START TIME INFORMATION] \n";
    cout << " HOUR : ";
    cin >> startHour;
    cout << " MINUTE : ";
    cin >> startMinute;

    time.setStartHour(startHour);
    time.setStartMinute(startMinute);

    int count = 1;
    for (Teacher tech: teachersList) {
        cout << "  ***" << "\n TEACHER " << count << "\n";
        cout << tech.showPersonInformation() << endl;
        count++;
    }

    int number;
    cout << " CHOOSE TEACHER ID : ";
    cin >> number;

    for (Teacher &tech: teachersList) {
        if (tech.getTeacherNumber() == number) {
            ob.assignTeacher(&tech);
        }
    }
}

bool Section::secondCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isTimeInterference = time.handleTimeInterference(other.time);
    bool isLocationInterference = _assignedLocation && other._assignedLocation &&
                                  _assignedLocation->handleLocationInterference(*(other._assignedLocation));
    bool isDayInterference = date.handleDayInterference(other.date);

    if (!(isTimeInterference && isLocationInterference && isDayInterference)) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

void Section::secondMessage() {
    cout << "CHOOSE ANOTHER TIME , LOCATION AND DATE!";
}

void Section::changeTimeAndLocationAndDate(vector<Location> locationsList, Section ob) {
    cout << "[CURRENT SECTION INFORMATION]\n";
    cout << showSectionInformation() << endl;

    int startHour;
    int startMinute;
    cout << " [START TIME INFORMATION] \n";
    cout << " HOUR : ";
    cin >> startHour;
    cout << " MINUTE : ";
    cin >> startMinute;

    time.setStartHour(startHour);
    time.setStartMinute(startMinute);

    int year, month, day;
    cout << " [DATE INFORMATION] \n";
    cout << " SECTION YEAR : ";
    cin >> year;

    cout << " SECTION MONTH : ";
    cin >> month;

    cout << " SECTION DAY : ";
    cin >> day;

    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);

    int count1 = 1;
    for (Location location: locationsList) {
        cout << "  ***" << "\n LOCATION " << count1 << "\n";
        cout << location.showLocationAddress() << endl;
        count1++;
    }

    int number1;
    cout << " CHOOSE LOCATION ID : ";
    cin >> number1;
    for (Location &loc: locationsList) {
        if (loc.getLocationID() == number1) {
            ob.assignLocation(&loc);
        }
    }
}

bool Section::thirdCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isExamDateInterference = date.handleExamDayInterference(other.date);

    if (!isExamDateInterference) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

void Section::thirdMessage() {
    cout << "CHOOSE ANOTHER EXAM DATE!";
}

void Section::changeExamDate() {
    cout << "[CURRENT SECTION INFORMATION]\n";
    cout << showSectionInformation() << endl;

    int examYear, examMonth, examDay;
    cout << " YEAR OF EXAM : ";
    cin >> examYear;

    cout << " MONTH OF EXAM : ";
    cin >> examMonth;

    cout << " DAY OF EXAM : ";
    cin >> examDay;

    date.setExamYear(examYear);
    date.setExamMonth(examMonth);
    date.setExamDay(examDay);
}

bool Section::toCheckTheInterference(Section &other) {
    bool isValid = true;

    if (!firstCaseOfInterference(other)) {
        isValid = false;
        firstMessage();
        return isValid;
    } else if (!secondCaseOfInterference(other)) {
        isValid = false;
        secondMessage();
        return isValid;
    } else if (!thirdCaseOfInterference(other)) {
        isValid = false;
        thirdMessage();
        return isValid;
    } else {
        return isValid;
    }

}


string Section::getSectionName() const {
    return _sectionName;
}

//void Section::editSection() {
//    cout << "CURRENT SECTION INFORMATION:\n";
//    cout << showSectionInformation() << endl;
//
//    string sectionName;
//    cout << " ENTER NEW SECTION NAME: ";
//    cin.ignore();
//    getline(cin, sectionName);
//
//    string answer;
//    bool isNeed;
//    cout << " DO YOU NEED PROJECTOR (YES OR NO) ? ";
//    cin.ignore();
//    getline(cin, answer);
//    if (answer == "YES") {
//        isNeed = true;
//    } else if (answer == "NO") {
//        isNeed = false;
//    }
//
//    int startHour;
//    int startMinute;
//    cout << " [NEW START TIME INFORMATION] \n";
//    cout << " HOUR : ";
//    cin >> startHour;
//    cout << " MINUTE : ";
//    cin >> startMinute;
//
//    int sectionDuration;
//    int examDuration;
//    cout << " [NEW DURATION INFORMATION] \n";
//    cout << " SECTION DURATION : ";
//    cin >> sectionDuration;
//    cout << " EXAM DURATION : ";
//    cin >> examDuration;
//
//    int year, month, day, examYear, examMonth, examDay, daynum;
//    cout << " [NEW DATE INFORMATION] \n";
//    cout << " SECTION YEAR : ";
//    cin >> year;
//
//    cout << " SECTION MONTH : ";
//    cin >> month;
//
//    cout << " SECTION DAY : ";
//    cin >> day;
//
//    cout << " YEAR OF EXAM : ";
//    cin >> examYear;
//
//    cout << " MONTH OF EXAM : ";
//    cin >> examMonth;
//
//    cout << " DAY OF EXAM : ";
//    cin >> examDay;
//
//    cout << " [NEW SECTION DAY]  \n";
//    cout << " ENTER A NUMBER FROM 0 to 6 (Saturday , ... , Friday) -> ";
//    cin >> daynum;
//
//}
//



