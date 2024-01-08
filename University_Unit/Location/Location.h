#ifndef UNIVERSITY_UNIT_LOCATION_H
#define UNIVERSITY_UNIT_LOCATION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Location {

private:

    string _facultyName;
    int _floorNumber;
    int _classNumber;
    static int _locationID;
    int _mainLocationID;

public:
    //constructor
    Location(string facultyName, int floorNumber, int classNumber);

public:
    [[nodiscard]] string showLocationAddress() const;

    void editLocation();

public:
    //for handling the Location interference
    // i use this function in (Section class)
    bool handleLocationInterference(Location &ob);

public:
    //getters

    [[nodiscard]] string getFacultyName() const;

    [[nodiscard]] int getFloorNumber() const;

    [[nodiscard]] int getClassNumber() const;

    [[nodiscard]] int getLocationID() const;

public:
    void saveToFile();
    static vector<Location> loadFromFIle();
};

#endif
