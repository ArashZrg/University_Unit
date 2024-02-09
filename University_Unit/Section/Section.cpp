#include "Section.h"
#include <string>


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
        date(year, month, day, examYear, examMonth, examDay, dayNum),
        _sectionID(sectionID) {
    existingSectionIDs.push_back(sectionID);

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

//TEACHER INTERFERENCE
bool Section::firstCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isTeacherInterference = _assignedTeacher && other._assignedTeacher &&
                                 _assignedTeacher->handleTeacherInterference(*(other._assignedTeacher));

    bool isTimeInterference = time.handleTimeInterference(other.time);
    bool isDayInterference = date.handleDayInterference(other.date);

    if (!(isTeacherInterference || isTimeInterference || isDayInterference)) {
        isValid = false;
        return isValid;
    }
    return isValid;

}
//    bool isTeacherInterference = _assignedTeacher->handleTeacherInterference(*other._assignedTeacher);

//    if (!(isTeacherInterference && isTimeInterference && isDayInterference)) {
//        isValid = false;
//        return isValid;
//    } else {
//        return isValid;
//    }

void Section::firstMessage() {
    cout << "CHOOSE ANOTHER TEACHER!\n";
}

void Section::changeTeacher(vector<Teacher> &teachersList, Section &ob) {
    cout << "[CURRENT SECTION INFORMATION]\n";
    cout << showSectionInformation() << endl;

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
//TEACHER INTERFERENCE

// LOCATION INTERFERENCE
bool Section::secondCaseOfInterference(Section &other) {
    bool isValid = true;

    bool isTimeInterference = time.handleTimeInterference(other.time);
    bool isLocationInterference = _assignedLocation->handleLocationInterference(*other._assignedLocation);
    bool isDayInterference = date.handleDayInterference(other.date);

    if (!(isTimeInterference || isLocationInterference || isDayInterference)) {
        isValid = false;
        return isValid;
    }
    return isValid;

}

//    bool isLocationInterference = _assignedLocation && other._assignedLocation &&
//                                  _assignedLocation->handleLocationInterference(*(other._assignedLocation));

//    if (!(isTimeInterference && isLocationInterference && isDayInterference)) {
//        isValid = false;
//        return isValid;
//    } else {
//        return isValid;
//    }

void Section::secondMessage() {
    cout << "CHOOSE ANOTHER LOCATION!\n";
}

void Section::changeLocation(vector<Location> &locationsList, Section &ob) {
    cout << "[CURRENT SECTION INFORMATION]\n";
    cout << showSectionInformation() << endl;

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
// LOCATION INTERFERENCE

//EXAM DATE INTERFERENCE
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
    cout << "CHOOSE ANOTHER DATE FOR EXAM!\n";
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
//EXAM DATE INTERFERENCE

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
