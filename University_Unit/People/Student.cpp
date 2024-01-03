//#include "Student.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//Student::Student(std::string firstName, std::string lastName, int age) : Person(firstName, lastName, age) {
//    _studentNumber++;
//    _distStudentNumber = _studentNumber;
//}
//
//string Student::showPersonInformation() {
//    string fullName = getFirstName() + " " + getLastName();
//    string result = "[Name: " + fullName + "]\n"
//                    + "[Age: " + to_string(getAge()) + "]\n"
//                    + "[Student Number : " + to_string(getStudentNumber()) + "]\n";
//
//    return result;
//}
//
//
//int Student::getStudentNumber() const {
//    return _distStudentNumber;
//}
//
//int Student::_studentNumber = 4023600;