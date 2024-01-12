#ifndef UNIVERSITY_UNIT_LOCATIONOPERATION_H
#define UNIVERSITY_UNIT_LOCATIONOPERATION_H


#include "../Location/Location.h"

class LocationOperation {
public:
    static void AddLocation(vector<Location> & locationsList);

    static void DeleteLocation(vector<Location> & locationsList);

    static void EditLocation(vector<Location> & locationsList);

    static void ShowLocation(vector<Location> & locationsList);

    static void saveLocationFile(const Location &location, const string &fileName);

    static void loadLocationFromFile(Location& location , const string& fileName);
public:

};


#endif //UNIVERSITY_UNIT_LOCATIONOPERATION_H
