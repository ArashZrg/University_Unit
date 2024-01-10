//
// Created by Arash on 1/10/2024.
//

#ifndef UNIVERSITY_UNIT_LOCATIONOPERATION_H
#define UNIVERSITY_UNIT_LOCATIONOPERATION_H


#include "../Location/Location.h"

class LocationOperation {
public:
    static void AddLocation(vector<Location> & locationsList);

    static void DeleteLocation(vector<Location> & locationsList);

    static void EditLocation(vector<Location> & locationsList);

    static void ShowLocation(vector<Location> & locationsList);
};


#endif //UNIVERSITY_UNIT_LOCATIONOPERATION_H
