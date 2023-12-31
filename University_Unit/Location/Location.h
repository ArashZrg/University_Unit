#ifndef UNIVERSITY_UNIT_LOCATION_H
#define UNIVERSITY_UNIT_LOCATION_H

#include <iostream>
#include <string>

using namespace std;

class Location {
private:
    string _buildingName;
    int _floorsNumber;
    int _roomNumberInEachFloor;
    string _buildingAddress;
public:

    Location(string buildingName ,int roomNumber ,int floorNumber , string buildingAddress);

    string showBuildingInformation();

    string getBuildingName();
    int getRoomNumber();
    int getFloorNumber();
    string getBuildingAddress();

};


#endif
