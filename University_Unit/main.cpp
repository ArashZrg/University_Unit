#include <iostream>
#include <string>
#include <vector>
#include "DateTime/Time.h"
#include "DateTime/Date.h"
#include "Location/Location.h"
#include "People/Teacher.h"
#include "People/Student.h"
#include "Section/Section.h"
#include <fstream>
#include <sstream>

using namespace std;

string whileMenu() {
    string result = string("      [Menu]\n")
                    + string(" *************** \n")
                    + string(" 1-SECTION \n")
                    + string(" 2-LOCATION \n")
                    + string(" 3-TEACHER \n")
                    + string(" 4-STUDENT \n")
                    + string(" 5-EXIT \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string sectionMenu() {
    string result = string(" 1-ADD SECTION \n")
                    + string(" 2-DELETE SECTION \n")
                    + string(" 3-EDIT SECTION \n")
                    + string(" 4-SHOW SECTION \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION ->");
    return result;
}

string locationMenu() {
    string result = string(" 1-ADD LOCATION \n")
                    + string(" 2-DELETE LOCATION \n")
                    + string(" 3-EDIT LOCATION \n")
                    + string(" 4-SHOW ALL LOCATION \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string teacherMenu() {

    string result = string(" 1-ADD TEACHER \n")
                    + string(" 2-DELETE TEACHER \n")
                    + string(" 3-EDIT TEACHER \n")
                    + string(" 4-SHOW ALL TEACHERS \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string studentMenu() {
    string result = string(" 1-ADD STUDENT \n")
                    + string(" 2-DELETE STUDENT \n")
                    + string(" 3-EDIT STUDENT \n")
                    + string(" 4-SHOW ALL STUDENTS \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string("CHOOSE OPTION -> ");
    return result;

}

int main() {

    vector<Section> sectionList;
    vector<Location> locationsList;
    vector<Teacher> teachersList;
    vector<Student> studentsList;
    vector<int> studentsNumbers;

    int OPTION;

    while (OPTION != 5) {

        cout << whileMenu();
        cin >> OPTION;
        cout << "*************** \n";

        if (OPTION == 5) {
            cout << "[MESSAGE FOR YOU -->" << " THANK YOU FOR USING OUR PROGRAM \003]";
        }

        switch (OPTION) {
            //Section Case
            case 1: {
                int sectionOption;
                cout << sectionMenu();
                cin >> sectionOption;
                cout << "*************** \n";

                switch (sectionOption) {
                    case 1: {
                        string sectionID;
                        cout << " ENTER SECTION ID: ";
                        cin.ignore();
                        getline(cin, sectionID);

                        string sectionName;
                        cout << " ENTER SECTION NAME: ";
                        cin.ignore();
                        getline(cin, sectionName);

                        string answer;
                        bool isNeed;
                        cout << " DO YOU NEED PROJECTOR (YES OR NO) ? ";
                        cin.ignore();
                        getline(cin, answer);
                        if (answer == "YES") {
                            isNeed = true;
                        } else if (answer == "NO") {
                            isNeed = false;
                        }

                        int startHour;
                        int startMinute;
                        cout << " [START TIME INFORMATION] \n";
                        cout << " HOUR : ";
                        cin >> startHour;
                        cout << " MINUTE : ";
                        cin >> startMinute;

                        int sectionDuration;
                        int examDuration;
                        cout << " [DURATION INFORMATION] \n";
                        cout << " SECTION DURATION : ";
                        cin >> sectionDuration;
                        cout << " EXAM DURATION : ";
                        cin >> examDuration;

                        int year, month, day, examYear, examMonth, examDay, daynum;
                        cout << " [DATE INFORMATION] \n";
                        cout << " SECTION YEAR : ";
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
                            count++;
                        }

                        int number1;
                        cout << " CHOOSE LOCATION ID : ";
                        cin >> number1;
                        for (Location &loc: locationsList) {
                            if (loc.getLocationID() == number) {
                                section.assignLocation(&loc);
                            }
                        }

                        cout << "[*CHECK THE INTERFERENCE*]\n";
                        for (Section sec: sectionList) {
                            if (!section.toCheckTheInterference(sec)) {
                                throw invalid_argument("SECTIONS HAVE INTERFERENCE WITH EACH OTHER!");
                            }
                        }

                        sectionList.push_back(section);
                        break;
                    }
                    case 2: {

                        cout << "ID OF EXIST SECTIONS : \n";
                        for (Section section: sectionList) {
                            cout << "[" << section.getSectionId() << "]" << endl;
                        }

                        string id;
                        cout << "ENTER YOUR PREFERRED SECTION ID -->";
                        cin.ignore();
                        getline(cin, id);

                        for (int i = 0; i < sectionList.size(); ++i) {
                            if (sectionList[i].getSectionId() == id) {
                                sectionList.erase(sectionList.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        string sectionID;
                        for (Section section: sectionList) {
                            cout << "[" << section.getSectionName() << " , "
                                 << section.getSectionId() << "]" << endl;
                        }

                        cout << "ENTER THE ID OF THE SECTION TO EDIT: ";
                        cin.ignore();
                        getline(cin, sectionID);

                        for (Section section: sectionList) {
                            if (section.getSectionId() == sectionID) {
//                                section.edit();
                                break;
                            }
                        }

                        break;
                    }
                    case 4: {
                        int count = 1;
                        for (Section &section: sectionList) {
                            cout << "  ***" << "\n SECTION " << count << "\n";
                            cout << section.showSectionInformation() << endl;
                            count++;
                        }
                        break;
                    }
                    case 5: {
                        break;
                    }
                }
                break;
            }
                //Location Case
            case 2: {

                int locationOption;
                cout << locationMenu();
                cin >> locationOption;
                cout << "*************** \n";

                switch (locationOption) {
                    case 1: {
                        string facultyName;
                        cout << "ENTER FACULTY NAME: ";
                        cin.ignore();
                        getline(cin, facultyName);

                        int floorNumber;
                        cout << "ENTER FLOOR NUMBER: ";
                        cin >> floorNumber;

                        int classNumber;
                        cout << "ENTER CLASS NUMBER: ";
                        cin >> classNumber;

                        Location location(facultyName, floorNumber, classNumber);
                        locationsList.push_back(location);

                        break;
                    }
                    case 2: {
                        cout << "ID OF EXIST LOCATIONS : \n";
                        for (Location location: locationsList) {
                            cout << "[" << location.getFacultyName() << " , " << location.getLocationID() << "]"
                                 << endl;
                        }

                        int number;
                        cout << "ENTER YOUR PREFERRED LOCATION ID -->";
                        cin >> number;
                        for (int i = 0; i < locationsList.size(); ++i) {
                            if (locationsList[i].getLocationID() == number) {
                                locationsList.erase(locationsList.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        int locationId;
                        for (Location location: locationsList) {
                            cout << "[" << location.getFacultyName() << " , "
                                 << location.getLocationID() << "]" << endl;
                        }
                        cout << "ENTER THE ID OF THE LOCATION TO EDIT: ";
                        cin >> locationId;

                        for (Location &loc: locationsList) {
                            if (loc.getLocationID() == locationId) {
                                loc.editLocation();
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        int count = 1;
                        for (Location location: locationsList) {
                            cout << "  ***" << "\n LOCATION " << count << "\n";
                            cout << location.showLocationAddress() << endl;
                            count++;
                        }
                        break;
                    }
                    case 5: {

                        break;
                    }
                }
                break;
            }
                //Teacher Case
            case 3: {

                int teacherOption;
                cout << teacherMenu();
                cin >> teacherOption;
                cout << "*************** \n";

                switch (teacherOption) {
                    case 1: {
                        string firstName;
                        cout << " ENTER FIRST NAME: ";
                        cin.ignore();
                        getline(cin, firstName);

                        string lastName;
                        cout << "ENTER LAST NAME: ";
                        getline(cin, lastName);

                        Teacher teacher(firstName, lastName);
                        teachersList.push_back(teacher);
                        break;
                    }
                    case 2: {
                        cout << "ID OF EXIST TEACHERS : \n";
                        for (Teacher tech: teachersList) {
                            cout << "[" << tech.getFirstName() << "_" << tech.getLastName() << " , "
                                 << tech.getTeacherNumber() << "]" << endl;
                        }
                        int number;
                        cout << "ENTER YOUR PREFERRED ID --> ";
                        cin >> number;
                        for (int i = 0; i < teachersList.size(); ++i) {
                            if (teachersList[i].getTeacherNumber() == number) {
                                teachersList.erase(teachersList.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        int teacherNumber;
                        for (Teacher tech: teachersList) {
                            cout << "[" << tech.getFirstName() << "_" << tech.getLastName() << " , "
                                 << tech.getTeacherNumber() << "]" << endl;
                        }
                        cout << "ENTER THE NUMBER OF THE TEACHER TO EDIT: ";
                        cin >> teacherNumber;

                        for (Teacher &tech: teachersList) {
                            if (tech.getTeacherNumber() == teacherNumber) {
                                tech.editTeacher();
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        int count = 1;
                        for (Teacher tech: teachersList) {
                            cout << "  ***" << "\n TEACHER " << count << "\n";
                            cout << tech.showPersonInformation() << endl;
                            count++;
                        }
                        break;
                    }
                    case 5: {
                        break;
                    }
                }
                break;
            }
                //Student Case
            case 4: {
                int studentOption;
                cout << studentMenu();
                cin >> studentOption;
                cout << "*************** \n";

                switch (studentOption) {
                    case 1: {
                        string firstName;
                        cout << "ENTER FIRST NAME: ";
                        cin.ignore();
                        getline(cin, firstName);

                        string lastName;
                        cout << "ENTER LAST NAME: ";
                        getline(cin, lastName);

                        Student student(firstName, lastName);
                        studentsList.push_back(student);
                        studentsNumbers.push_back(student.getStudentNumber());


                        break;
                    }
                    case 2: {
                        cout << "EXIST STUDENTS NUMBERS: \n";
                        for (Student student: studentsList) {
                            cout << student.getStudentNumber() << endl;
                        }
                        int number;
                        cout << "ENTER YOUR PREFERRED Number --> ";
                        cin >> number;
                        for (int i = 0; i < studentsList.size(); ++i) {
                            if (studentsList[i].getStudentNumber() == number) {
                                studentsList.erase(studentsList.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        int studentNumber;
                        for (Student student: studentsList) {
                            cout << "[" << student.getFirstName() << "_" << student.getLastName() << " , "
                                 << student.getStudentNumber() << "]" << endl;
                        }
                        cout << "ENTER THE NUMBER OF THE STUDENT TO EDIT: ";
                        cin >> studentNumber;

                        for (Student &student: studentsList) {
                            if (student.getStudentNumber() == studentNumber) {
                                student.editStudent();
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        int count = 1;
                        for (Student student: studentsList) {
                            cout << "  ***" << "\n STUDENT " << count << "\n";
                            cout << student.showPersonInformation() << endl;
                            count++;
                        }
                        break;
                    }
                    case 5: {
                        break;
                    }
                }
                break;
            }

        }
    }
}
