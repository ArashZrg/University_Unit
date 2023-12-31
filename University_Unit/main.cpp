#include <iostream>
#include <string>
#include <vector>
#include "DateTime/Time.h"
//#include "People/Person.h"
//#include "People/Student.h"

using namespace std;

int main() {

    Time test(8 , 0 , 3 , 5 );
    cout << test.computeFinishTime() << endl;
    cout << test.showClassStartTime() << endl;
    cout << test.showClassDuration() << endl;
    cout << test.showClassFinishTime() << endl;
    cout << test.getStartHour() << endl;
    cout << test.getStartMinute() << endl;
    cout << test.getDuration() << endl;
    cout << test.getExmaDuration() << endl;
    cout << test.getFinishHour() << endl;
    cout << test.getFinishMinute() << endl;

//    Student s1("Arash", "Zarghami", 18, 234567);
//    Student s2("Mohammad", "Rahi", 19, 234567);
//    Student s3("Mobin", "Assary", 18, 23456);
//    Student s4("Mahdi", "Mazaheri", 20, 119239);

//    cout << s1.getStudentNumber() << endl;
//    cout << s2.getStudentNumber() << endl;
//    cout << s3.getStudentNumber() << endl;
//    cout << s4.getStudentNumber() << endl;

//    cout << s1.getIdNumber() << endl;
//    cout << s2.getIdNumber() << endl;
//    cout << s3.getIdNumber() << endl;
//    cout << s4.getIdNumber() << endl;
//
//    cout << s1.getAge();
//    cout << s1.getFirstName();
//    cout << s1.getLastName();

//    cout << s1.showPersonInformation() << endl;
//    cout << s2.showPersonInformation() << endl;
//    cout << s3.showPersonInformation() << endl;
//    cout << s4.showPersonInformation() << endl;



}
