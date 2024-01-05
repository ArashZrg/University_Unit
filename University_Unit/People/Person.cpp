#include "Person.h"
#include <string>

using namespace std;

Person::Person(string firstName, string lastName) : _firstname(firstName),
                                                    _lastName(lastName) {}

string Person::getFirstName() {
    return _firstname;
}

string Person::getLastName() {
    return _lastName;
}




