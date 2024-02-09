#include <iostream>
#include <string>
#include <vector>
#include "DateTime/Time.h"
#include "DateTime/Date.h"
#include "Location/Location.h"
#include "People/Teacher.h"
#include "People/Student.h"
#include "Section/Section.h"


// Folders and classes for (Main)
#include "Menu/Menu.h"
#include "MainOperation/SectionOperation.h"
#include "MainOperation/LocationOperation.h"
#include "MainOperation/TeacherOperation.h"
#include "MainOperation/StudentOperation.h"
// Folders and classes for (Main)

using namespace std;


int main() {

    vector<Section> sectionsList;
    vector<Location> locationsList;
    vector<Teacher> teachersList;
    vector<Student> studentsList;
    vector<int> studentsNumbers;


    int OPTION;

    while (OPTION != 5) {

        cout << Menu::whileMenu();
        cin >> OPTION;
        cout << "*************** \n";

        if (OPTION == 5) {
            cout << "[MESSAGE FOR YOU -->" << " THANK YOU FOR USING OUR PROGRAM \003]";
        }

        switch (OPTION) {

            //Section Case
            case 1: {
                int sectionOption;
                cout << Menu::sectionMenu();
                cin >> sectionOption;
                cout << "*************** \n";

                switch (sectionOption) {
                    case 1: {
                        //Need To Check Exactly Here
                        string sectionID;
                        cout << "  ENTER SECTION ID: ";
                        cin.ignore();
                        getline(cin, sectionID);
                        while (!Section::isSectionIdValid(sectionID)) {
                            cout << "[*!THIS SECTION ID ALREADY EXIST!*]\n";
                            cout << " ENTER NEW SECTION ID: ";
                            getline(cin, sectionID);
                        }
                        //Need To Check Exactly Here

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
                                }
                            }
                        }

                        sectionsList.push_back(section);
                        break;
                    }
                    case 2: {
                        SectionOperation::DeleteSection(sectionsList);
                        break;
                    }
                    case 3: {
                        SectionOperation::ShowSection(sectionsList);
                        break;
                    }
                    case 4: {
                        break;
                    }
                }
                break;
            }

                //Location Case
            case 2: {

                int locationOption;
                cout << Menu::locationMenu();
                cin >> locationOption;
                cout << "*************** \n";

                switch (locationOption) {
                    case 1: {
                        LocationOperation::AddLocation(locationsList);
                        break;
                    }
                    case 2: {
                        LocationOperation::DeleteLocation(locationsList);
                        break;
                    }
                    case 3: {
                        LocationOperation::EditLocation(locationsList);
                        break;
                    }
                    case 4: {
                        LocationOperation::ShowLocation(locationsList);
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
                cout << Menu::teacherMenu();
                cin >> teacherOption;
                cout << "*************** \n";

                switch (teacherOption) {
                    case 1: {
                        TeacherOperation::AddTeacher(teachersList);
                        break;
                    }
                    case 2: {
                        TeacherOperation::DeleteTeacher(teachersList);
                        break;
                    }
                    case 3: {
                        TeacherOperation::EditTeacher(teachersList);
                        break;
                    }
                    case 4: {
                        TeacherOperation::ShowTeacher(teachersList);
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
                cout << Menu::studentMenu();
                cin >> studentOption;
                cout << "*************** \n";

                switch (studentOption) {
                    case 1: {
                        StudentOperation::AddStudent(studentsList, studentsNumbers);
                        break;
                    }
                    case 2: {
                        StudentOperation::DeleteStudent(studentsList);
                        break;
                    }
                    case 3: {
                        StudentOperation::EditStudent(studentsList);
                        break;
                    }
                    case 4: {
                        StudentOperation::ShowStudents(studentsList);
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
