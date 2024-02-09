#include "LocationOperation.h"
#include <iostream>


void LocationOperation::AddLocation(vector<Location> &locationsList) {
    string facultyName;
    cout << "ENTER FACULTY NAME: ";
    cin.ignore();
    getline(cin, facultyName);

    int floorNumber;
    cout << "ENTER FLOOR NUMBER: ";
    cin >> floorNumber;

    int classNumber;
    cout << "ENTER CLASS NUMBER: ";
    cin >> classNumber;

    Location location(facultyName, floorNumber, classNumber);

    locationsList.push_back(location);
}

void LocationOperation::DeleteLocation(vector<Location> &locationsList) {
    cout << "ID OF EXIST LOCATIONS : \n";
    for (Location location: locationsList) {
        cout << "[" << location.getFacultyName() << " , " << location.getLocationID() << "]"
             << endl;
    }

    int number;
    cout << "ENTER YOUR PREFERRED LOCATION ID -->";
    cin >> number;
    for (int i = 0; i < locationsList.size(); ++i) {
        if (locationsList[i].getLocationID() == number) {
            locationsList.erase(locationsList.begin() + i);
            break;
        }
    }
}

void LocationOperation::EditLocation(vector<Location> &locationsList) {
    int locationId;
    for (Location location: locationsList) {
        cout << "[" << location.getFacultyName() << " , "
             << location.getLocationID() << "]" << endl;
    }
    cout << "ENTER THE ID OF THE LOCATION TO EDIT: ";
    cin >> locationId;

    for (Location &loc: locationsList) {
        if (loc.getLocationID() == locationId) {
            loc.editLocation();
            break;
        }
    }
}

void LocationOperation::ShowLocation(vector<Location> &locationsList) {
    int count = 1;
    for (Location location: locationsList) {
        cout << "  ***" << "\n LOCATION " << count << "\n";

        cout << location.showLocationAddress() << endl;
        count++;
    }
}

