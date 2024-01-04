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

    Person(string firstName, string lastName);

    string getFirstName();

    string getLastName();

    virtual string showPersonInformation() = 0;

};

#endif