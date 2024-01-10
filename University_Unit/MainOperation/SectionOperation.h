//
// Created by Arash on 1/10/2024.
//

#ifndef UNIVERSITY_UNIT_SECTIONOPERATION_H
#define UNIVERSITY_UNIT_SECTIONOPERATION_H

#include "../Section/Section.h"

class SectionOperation {

public:

    static void AddSecion();

    static void DeleteSection(vector<Section> &sectionsList);

    static void EditSection();

    static void ShowSection(vector<Section> &sectionsList);


};


#endif //UNIVERSITY_UNIT_SECTIONOPERATION_H
