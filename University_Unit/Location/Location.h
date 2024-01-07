#ifndef UNIVERSITY_UNIT_LOCATION_H
#define UNIVERSITY_UNIT_LOCATION_H

#include <iostream>
#include <string>

using namespace std;

class Location {

private:

    string _facultyName;
    int _floorNumber;
    int _classNumber;

    static int _locationID;
    int _mainLocationID;

public:

    Location(string facultyName, int floorNumber, int classNumber);

    [[nodiscard]] string getFacultyName() const;

    [[nodiscard]] int getFloorNumber() const;

    [[nodiscard]] int getClassNumber() const;

    [[nodiscard]] int getLocationID() const;

    [[nodiscard]] string showLocationAddress() const;

    void editLocation();

    bool handleLocationInterference(Location& ob) const;

};

#endif
