#include "Location.h"
#include <iostream>
#include <fstream>
#include <sstream>

Location::Location(string facultyName, int floorNumber, int classNumber) :
        _facultyName(facultyName), _floorNumber(floorNumber), _classNumber(classNumber) {

    _locationID++;
    _mainLocationID = _locationID;
}


string Location::showLocationAddress() const {
    string result = string("*ADDRESS*\n") +
                    "[Faculty Name: " + getFacultyName() + "]\n" +
                    "[Floor Number : " + to_string(getFloorNumber()) + "]\n" +
                    "[Class Number : " + to_string(getClassNumber()) + "]\n";
    return result;
}

void Location::editLocation() {
    cout << "CURRENT LOCATION INFORMATION:\n";
    cout << showLocationAddress() << endl;

    string facultyName;
    cout << "ENTER NEW FACULTY NAME: ";
    cin.ignore();
    getline(cin, facultyName);

    int floorNumber;
    cout << "ENTER NEW FLOOR NUMBER: ";
    cin >> floorNumber;

    int classNumber;
    cout << "ENTER NEW CLASS NUMBER: ";
    cin >> classNumber;

    _facultyName = facultyName;
    _floorNumber = floorNumber;
    _classNumber = classNumber;

    cout << "LOCATION UPDATED SUCCESSFULLY!\n";

}

bool Location::handleLocationInterference(Location &ob) {
    bool isValid = true;

    if ((_facultyName == ob._facultyName) && (_floorNumber == ob._floorNumber) && (_classNumber == ob._classNumber)) {
        isValid = false;
        return isValid;
    }

    return isValid;
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


int Location::_locationID = 0;

void Location::saveToFile() {
    ofstream file("locations.txt", ios::app);
    if (file.is_open()) {
        file << getFacultyName() << "," << getFloorNumber() << "," << getClassNumber() << "\n";
        file.close();
    } else {
        cerr << "ERROR OPENING FILE FOR SAVING LOCATIONS DATA.\n";
    }
}

vector<Location> Location::loadFromFIle() {
    vector<Location> locations;
    ifstream file("locations.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string facultyName;
            int floorNumber, classNumber;
            getline(ss, facultyName, ',');
            ss >> floorNumber;
            ss.ignore();
            ss >> classNumber;
            locations.emplace_back(facultyName, floorNumber, classNumber);
        }
        file.close();
    } else {
        cerr << "ERROR OPENING FILE FOR LOADING LOCATIONS DATA.\n";
    }
    return locations;
}