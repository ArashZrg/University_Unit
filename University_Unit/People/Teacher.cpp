//#include "Teacher.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//Teacher::Teacher(string firstName, string lastName, int age) : Person(firstName, lastName, age) {
//    _teacherNumber++;
//    _distTeacherNumber = _teacherNumber;
//}
//
//int Teacher::getTeacherNumber() {
//    return _distTeacherNumber;
//}
//
//string Teacher::showPersonInformation() {
//    string fullName = getFirstName() + " " + getLastName();
//    string result = "[Name: " + fullName + "]\n"
//                    + "[Age: " + to_string(getAge()) + "]\n"
//                    + "[Teacher Number: " + to_string(getTeacherNumber()) + "]\n";
//
//    return result;
//}