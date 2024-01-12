#include "LocationOperation.h"
#include <iostream>
#include <fstream>
#include <sstream>


void LocationOperation::AddLocation(vector<Location> & locationsList) {
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

    saveLocationFile(location, "location.txt");
    locationsList.push_back(location);
}

void LocationOperation::DeleteLocation(vector<Location> & locationsList) {
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

void LocationOperation::EditLocation(vector<Location> & locationsList) {
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

void LocationOperation::ShowLocation(vector<Location> & locationsList) {
    int count = 1;
    for (Location location: locationsList) {
        cout << "  ***" << "\n LOCATION " << count << "\n";

        loadLocationFromFile(location, "location.txt");
        cout << location.showLocationAddress() << endl;
        count++;
    }
}

//void LocationOperation::saveLocationFile(const Location &location, const std::string &fileName) {
//    ofstream file(fileName);
//
//    if (file.is_open()) {
//        file << location.getFacultyName() << endl;
//        file << location.getFloorNumber() << endl;
//        file << location.getClassNumber() << endl;
//        file << location.getLocationID() << endl;
//
//        file.close();
//        cout << "LOCATION SAVED TO FILE SUCCESSFULLY.\n";
//    } else {
//        cout << "UNABLE TO OPEN THE FILE FOR SAVING.\n";
//    }
//}
//
//void LocationOperation::loadLocationFromFile(Location &location, const std::string &fileName) {
//    ifstream file(fileName);
//
//    if (file.is_open()) {
//        string facultyName;
//        int floorNubmer, classNumber, locationID;
//
//        getline(file, facultyName);
//        file >> floorNubmer >> classNumber >> locationID;
//
//        location = Location(facultyName, floorNubmer, classNumber);
//
//        file.close();
//        cout << "LOCATION LOADED FROM FILE SUCCESSFULLY.\n";
//    } else {
//        cout << "UNABLE TO OPEN FILE FOR LOADING.\n";
//    }
//}

void LocationOperation::saveLocationFile(const Location &location, const std::string &fileName) {
    ofstream file(fileName);

    if (file.is_open()) {
        file << location.getFacultyName() << " " << location.getFloorNumber() << " " << location.getClassNumber() << " "
             << location.getLocationID() << endl;
        file.close();
        cout << "LOCATION SAVED TO FILE SUCCESSFULLY.\n";
    } else {
        cout << "UNABLE TO OPEN THE FILE FOR SAVING.\n";
    }
}

void LocationOperation::loadLocationFromFile(Location &location, const std::string &fileName) {
    ifstream file(fileName);

    if (file.is_open()) {
        string facultyName;
        int floorNubmer, classNumber, locationID;
        string str;
        getline(file, str);
        stringstream ss(str);
        ss >> facultyName;
        ss >> floorNubmer;
        ss >> classNumber;
        ss >> locationID;


        location = Location(facultyName, floorNubmer, classNumber);

        file.close();
    }
}