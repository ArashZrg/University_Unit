#include "Location.h"

Location::Location(string facultyName, int floorNumber, int classNumber) :
        _facultyName(facultyName), _floorNumber(floorNumber), _classNumber(classNumber) {

    _locationID++;
    _mainLocationID = _locationID;
}

string Location::getFacultyName() const {
    return _facultyName;
}

int Location::getFloorNumber() const {
    return _floorNumber;
}

int Location::getClassNumber() const {
    return _classNumber;
}

int Location::getLocationID() const {
    return _mainLocationID;
}


string Location::showLocationAddress() const {
    string result = string("*ADDRESS*\n") +
                    "[Faculty Name: " + getFacultyName() + "]\n" +
                    "[Floor Number : " + to_string(getFloorNumber()) + "]\n" +
                    "[Class Number : " + to_string(getClassNumber()) + "]\n";
    return result;
}


int Location::_locationID = 00;