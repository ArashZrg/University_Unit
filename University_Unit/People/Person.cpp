#include "Person.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Person::Person(string firstName, string lastName, int age) : _firstname(firstName),
                                                        _lastName(lastName) {

    if (isValidAge(age)) {
        _age = age;
    } else {
        throw invalid_argument("Illegal Age!");
    }

}

bool Person::isValidAge(int age) {
    bool isValid = true;

    if (age < 18) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

string Person::getFirstName() {
    return _firstname;
}

string Person::getLastName() {
    return _lastName;
}

int Person::getAge() {
    return _age;
}


