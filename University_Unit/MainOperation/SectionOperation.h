
#ifndef UNIVERSITY_UNIT_SECTIONOPERATION_H
#define UNIVERSITY_UNIT_SECTIONOPERATION_H

#include "../Section/Section.h"
#include <vector>
#include "../Menu/Menu.h"

class SectionOperation {

public:

    static void AddSecion(vector<int> &studentsNumbers, vector<Teacher> &teachersList, vector<Location> &locationsList,
                          vector<Section> &sectionsList);

    static void DeleteSection(vector<Section> &sectionsList);

    static void ShowSection(vector<Section> &sectionsList);

};


#endif //UNIVERSITY_UNIT_SECTIONOPERATION_H
