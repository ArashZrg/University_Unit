#ifndef UNIVERSITY_UNIT_PERSON_H
#define UNIVERSITY_UNIT_PERSON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {

private:

    string _firstname;
    string _lastName;

public:
    //constructor
    Person(string firstName, string lastName);

public:

    //pure virtual for showing the information of Person
    virtual string showPersonInformation() = 0;

public:
    //setters
    void setFirstName(string firstName);

    void setLastName(string lastName);

public:
    //getters
    string getFirstName();

    string getLastName();
};

#endif