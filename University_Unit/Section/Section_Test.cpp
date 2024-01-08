//#include <iostream>
//#include <string>
//#include <vector>
//#include "Section.h"
//
//using namespace std;
//
//int main() {
//
//
//    vector<Location> locationsList;
//    vector<Teacher> teachersList;
//    vector<Student> studentsList;
//    vector<int> studentsNumbersList;
//    vector<Section> sectionsList;
//
//    cout << "start teacher\n";
//    for (int i = 0; i < 2; ++i) {
//        string name;
//        cin.ignore();
//        getline(cin, name);
//        string family;
//        cin.ignore();
//        getline(cin, family);
//        Teacher teacher(name, family);
//        teachersList.push_back(teacher);
//    }
//    cout << "finish teacher\n\n";
//
//    cout << "start student\n";
//    for (int i = 0; i < 2; ++i) {
//        string name;
//        getline(cin, name);
//        cin.ignore();
//        string family;
//        cin.ignore();
//        getline(cin, family);
//        Student student(name, family);
//        studentsList.push_back(student);
//        studentsNumbersList.push_back(student.getStudentNumber());
//    }
//    cout << "finish student\n\n";
//
//    cout << "start location\n";
//
//    for (int i = 0; i < 2; ++i) {
//        string name;
//        cin.ignore();
//        getline(cin, name);
//        int floor;
//        cin >> floor;
//        int number;
//        cin >> number;
//        Location location(name, floor, number);
//        locationsList.push_back(location);
//    }
//    cout << "finish location\n\n";
//
//    cout << "start section\n";
//    for (int i = 0; i < 2; ++i) {
//        string sectionId;
//        cout << "ENTER SECTION ID: ";
//        cin.ignore();
//        getline(cin, sectionId);
//
//        string sectionNmae;
//        cout << "ENTER SECTION NAME: ";
//        cin.ignore();
//        getline(cin, sectionNmae);
//
//        string answer;
//        bool isNeed;
//        cout << "DO YOU NEED PROJECTOR ? (YES OR NO) : ";
//        cin.ignore();
//        getline(cin, answer);
//        if (answer == "yes") {
//            isNeed = true;
//        } else if (answer == "no") {
//            isNeed = false;
//        }
//
//        int startHour;
//        int startMinute;
//        cout << "ENTER SECTION START HOUR : \n";
//        cout << "HOUR : ";
//        cin >> startHour;
//        cout << "MINUTE : ";
//        cin >> startMinute;
//
//        int sectionDuration;
//        int examDuration;
//        cout << "ENTER DURATION : \n";
//        cout << "SECTION DURATION : ";
//        cin >> sectionDuration;
//        cout << "EXAM DURATION : ";
//        cin >> examDuration;
//
//        int year, month, day, examYear, examMonth, examDay;
//        cout << "ENTER BY ORDER : \n";
//        cout << "YEAR : ";
//        cin >> year;
//
//        cout << "MONTH : ";
//        cin >> month;
//
//        cout << "DAY : ";
//        cin >> day;
//
//        cout << "YEAR OF EXAM : ";
//        cin >> examYear;
//
//        cout << "MONTH OF EXAM : ";
//        cin >> examMonth;
//
//        cout << "DAY OF EXAM : ";
//        cin >> examDay;
//
//        int dayNum;
//        cout << "ENTER NUMBER FORM 0 TO 6 (SATURDAY , ... , FRIDAY) : ";
//        cin >> dayNum;
//
//        Section section(sectionId, sectionNmae, isNeed, startHour, startMinute, sectionDuration,
//                        examDuration, year, month, day, examYear, examMonth, examDay, dayNum, studentsNumbersList);
//
//        for (Teacher &tech: teachersList) {
//            cout << "\n teachers : " << tech.getTeacherNumber() << " , ";
//        }
//
//        for (Teacher &tech: teachersList) {
//            int number;
//            cout << "CHOOSE TEACHER : ";
//            cin >> number;
//            if (number == tech.getTeacherNumber()) {
//                section.assignTeacher(&tech);
//            }
//
//        }
//
//        for (Location &loc: locationsList) {
//            cout << "locations : " << loc.getLocationID() << " , ";
//        }
//        cout <<endl;
//        for (Location &loc: locationsList) {
//            int number;
//            cout << "CHOOSE location : ";
//            cin >> number;
//            if (number == loc.getLocationID()) {
//                section.assignLocation(&loc);
//            }
//        }
//
//        sectionsList.push_back(section);
//    }
//    cout << "finish section\n\n";
//
//    for (Section &sec: sectionsList) {
//        cout << sec.showSectionInformation() << endl;
//    }
//
//
//}