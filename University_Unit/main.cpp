#include <iostream>
#include <string>
#include <vector>
#include "DateTime/Time.h"
#include "DateTime/Date.h"
#include "Location/Location.h"
#include "People/Person.h"
#include "People/Teacher.h"
#include "People/Student.h"
#include "Section/Section.h"

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

string locationMenu() {
    string result = string(" 1-ADD LOCATION \n")
                    + string(" 2-DELETE LOCATION \n")
                    + string(" 3-EDIT LOCATION \n")
                    + string(" 4-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string teacherMenu() {
    string result = string(" 1-ADD TEACHER \n")
                    + string(" 2-DELETE TEACHER \n")
                    + string(" 3-EDIT TEACHER \n")
                    + string(" 4-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string studentMenu(){
    string result = string(" 1-ADD STUDENT \n")
                    + string(" 2-DELETE STUDENT \n")
                    + string(" 3-EDIT STUDENT \n")
                    + string(" 4-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

int main() {

    vector<Location> __LOCATIONS__;
    vector<Teacher> __TEACHERS__;
    vector<Student> __STUDENTS__;

    int OPTION = 0;

    while (OPTION != 5) {

        cout << whileMenu();
        cin >> OPTION;
        cout << "*************** \n";

        switch (OPTION) {

            case 1: {
                break;
            }

            case 2: {

                int locationOption;
                cout << locationMenu();
                cin >> locationOption;

                switch (locationOption) {
                    case 1: {
                        string facultyName;
                        cout << "ENTER FACULTY NAME: \n";
                        getline(cin, facultyName);

                        int floorNumber;
                        cout << "ENTER FLOOR NUMBER: \n";
                        cin >> floorNumber;

                        int classNumber;
                        cout << "ENTER CLASS NUMBER: \n";
                        cin >> classNumber;

                        Location location(facultyName, floorNumber, classNumber);
                        __LOCATIONS__.push_back(location);
                        break;
                    }
                    case 2: {
                        cout << "ID OF EXIST LOCATIONS : ";
                        for (Location loc: __LOCATIONS__) {
                            cout << loc.getLocationID() << " , ";
                        }
                        int number;
                        cout << '\n' << "WHICH LOCATION DO YOU WANT TO DELETE?";
                        cin >> number;
                        for (int i = 0; i < __LOCATIONS__.size(); ++i) {
                            if (__LOCATIONS__[i].getLocationID() == number) {
                                __LOCATIONS__.erase(__LOCATIONS__.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        int locationId;
                        cout << "ENTER THE ID OF THE LOCATION TO EDIT: ";
                        cin >> locationId;

                        for (Location &loc: __LOCATIONS__) {
                            if (loc.getLocationID() == locationId) {
                                loc.editLocation();
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        break;
                    }
                }

                break;

            }

            case 3: {
                int teacherOption;
                cout << teacherMenu();
                cin >> teacherOption;

                switch (teacherOption) {
                    case 1: {
                        string firstName;
                        cout << "ENTER FIRST NAME: ";
                        cin.ignore();
                        getline(cin, firstName);

                        string lastName;
                        cout << "ENTER LAST NAME: ";
                        cin.ignore();
                        getline(cin, lastName);

                        Teacher teacher(firstName , lastName);
                        __TEACHERS__.push_back(teacher);
                        break;
                    }
                    case 2:{
                        cout << "ID OF EXIST TEACHERS : \n";
                        for(Teacher tech:__TEACHERS__){
                            cout << tech.getTeacherNumber() << " , ";
                        }
                        int number;
                        cin >> number;
                        for(int i= 0; i<__TEACHERS__.size(); ++i){
                            if(__TEACHERS__[i].getTeacherNumber() == number){
                                __TEACHERS__.erase(__TEACHERS__.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3:{
                        int teacherNumber;
                        cout << "ENTER THE NUMBER OF THE TEACHER TO EDIT: ";
                        cin >> teacherNumber;

                        for(Teacher tech:__TEACHERS__){
                            if(tech.getTeacherNumber() == teacherNumber){
                                tech.editTeacher();
                                break;
                            }
                        }
                        break;
                    }
                    case 4:{
                        break;
                    }
                }
                break;
            }

            case 4: {
                int studentOption;
                cout << studentMenu();
                cin >> studentOption;

                switch (studentOption) {
                    case 1:{
                        string firstName;
                        cout << "ENTER FIRST NAME: ";
                        cin.ignore();
                        getline(cin , firstName);

                        string lastName;
                        cout << "ENTER LAST NAME: ";
                        cin.ignore();
                        getline(cin , lastName);

                        Student student(firstName , lastName);

                        __STUDENTS__.push_back(student);

                        break;
                    }
                    case 2:{
                        cout << "ID OF EXIST STUDENTS : \n";
                        for(Student student:__STUDENTS__){
                            cout << student.getStudentNumber() << " , ";
                        }
                        int number;
                        cin >> number;
                        for(int i = 0 ; i < __STUDENTS__.size(); ++i){
                            if(__STUDENTS__[i].getStudentNumber() == number){
                                __STUDENTS__.erase(__STUDENTS__.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3:{
                        int studentNumber;
                        cout << "ENTER THE NUMBER OF THE TEACHER TO EDIT: ";
                        cin >> studentNumber;

                        for(Student student:__STUDENTS__){
                            if(student.getStudentNumber() == studentNumber){
                                student.editStudent();
                                break;
                            }
                        }
                        break;
                    }
                    case 4:{
                        break;
                    }
                }
                break;
            }

        }

    }

}
