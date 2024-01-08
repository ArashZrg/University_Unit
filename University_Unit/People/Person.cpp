#include "Person.h"
#include <string>

using namespace std;

Person::Person(string firstName, string lastName)
        : _firstname(firstName),
          _lastName(lastName) {}

string Person::getFirstName() {
    return _firstname;
}

string Person::getLastName() {
    return _lastName;
}

void Person::setFirstName(string firstName) {
    _firstname = firstName;
}

void Person::setLastName(string lastName) {
    _lastName = lastName;
}




