

#include "SectionOperation.h"


void
SectionOperation::AddSecion(vector<int> &studentsNumbers, vector<Teacher> &teachersList, vector<Location> &locationsList,
                            vector<Section> &sectionsList) {
    string sectionID;
    cout << "  ENTER SECTION ID: ";
    cin.ignore();
    getline(cin, sectionID);

    //CHECK THE ID
    while (!Section::isSectionIdValid(sectionID)) {
        cout << "[*!THIS SECTION ID ALREADY EXIST!*]\n";
        cout << " ENTER NEW SECTION ID: ";
        getline(cin, sectionID);
    }

    string sectionName;
    cout << " ENTER SECTION NAME: ";
    getline(cin, sectionName);

    string answer;
    bool isNeed;
    cout << " DO YOU NEED PROJECTOR (YES OR NO) ? ";
    getline(cin, answer);
    if (answer == "YES") {
        isNeed = true;
    } else if (answer == "NO") {
        isNeed = false;
    }


    int startHour;
    int startMinute;
    cout << " [START TIME INFORMATION] \n";
    cout << "  HOUR : ";
    cin >> startHour;
    cout << " MINUTE : ";
    cin >> startMinute;


    //Need To Check Exactly Here
    int sectionDuration;
    int examDuration;
    cout << " [DURATION INFORMATION] \n";
    cout << "  SECTION DURATION : ";
    cin >> sectionDuration;
    cout << " EXAM DURATION : ";
    cin >> examDuration;
    while (!(Time::isValidDuration(sectionDuration) && Time::isValidExamDuration(examDuration))) {
        cout << "[*!SECTION DURATION MOST BE 1 , 2 OR 3 HOUR!*]\n";
        cout << " [*!EXAM DURATION MOST BE 2 OR 3 HOUR!*]\n";
        cout << "  NEW SECTION DURATION : ";
        cin >> sectionDuration;
        cout << " NEW EXAM DURATION : ";
        cin >> examDuration;
    }
    //Need To Check Exactly Here


    int year, month, day, examYear, examMonth, examDay, daynum;
    cout << " [DATE INFORMATION] \n";
    cout << "  SECTION YEAR : ";
    cin >> year;

    cout << " SECTION MONTH : ";
    cin >> month;

    cout << " SECTION DAY : ";
    cin >> day;

    cout << " YEAR OF EXAM : ";
    cin >> examYear;

    cout << " MONTH OF EXAM : ";
    cin >> examMonth;

    cout << " DAY OF EXAM : ";
    cin >> examDay;

    cout << " [SECTION DAY]  \n";
    cout << " ENTER A NUMBER FROM 0 to 6 (Saturday , ... , Friday) -> ";
    cin >> daynum;

    Section section(sectionID, sectionName, isNeed, startHour, startMinute, sectionDuration,
                    examDuration, year, month, day, examYear, examMonth, examDay, daynum,
                    studentsNumbers);


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
            section.assignTeacher(&tech);
        }
    }

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
            section.assignLocation(&loc);
        }
    }


    for (Section sec: sectionsList) {
        cout << "[*CHECK THE INTERFERENCE*]\n";
        while (!section.toCheckTheInterference(sec)) {
            int op;
            cout << Menu::interferenceMenu();
            cin >> op;
            cout << "*************** \n";

            switch (op) {
                case 1: {
                    section.changeTeacher(teachersList, section);
                    break;
                }
                case 2: {
                    section.changeLocation(locationsList, section);
                    break;
                }
                case 3: {
                    section.changeExamDate();
                    break;
                }
                case 4: {
                    break;
                }
            }
        }
    }

    sectionsList.push_back(section);
}

void SectionOperation::DeleteSection(vector<Section> &sectionsList) {
    cout << "ID OF EXIST SECTIONS : \n";
    for (Section section: sectionsList) {
        cout << "[" << section.getSectionId() << "]" << endl;
    }

    string id;
    cout << "ENTER YOUR PREFERRED SECTION ID -->";
    cin.ignore();
    getline(cin, id);

    for (int i = 0; i < sectionsList.size(); ++i) {
        if (sectionsList[i].getSectionId() == id) {
            sectionsList.erase(sectionsList.begin() + i);
            break;
        }
    }
}


void SectionOperation::ShowSection(vector<Section> &sectionsList) {
    int count = 1;
    for (Section &section: sectionsList) {
        cout << "  ***" << "\n SECTION " << count << "\n";
        cout << section.showSectionInformation() << endl;
        count++;
    }
}