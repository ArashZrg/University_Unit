#ifndef UNIVERSITY_UNIT_PERSON_H
#define UNIVERSITY_UNIT_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person {

private:
    string _firstname;
    string _lastName;
    int _age;
    int _idNumber;

public:

    Person(string firstName, string lastName, int age );


    bool isValidAge(int age);

    string getFirstName();

    string getLastName();

    int getAge();

    virtual string showPersonInformation() = 0;

};


#endif