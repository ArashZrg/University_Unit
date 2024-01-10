//
// Created by Arash on 1/10/2024.
//

#include "SectionOperation.h"



//void SectionOperation::AddSecion() {}

//void SectionOperation::EditSection() {}

void SectionOperation::DeleteSection(vector<Section> & sectionsList) {
    cout << "ID OF EXIST SECTIONS : \n";
    for (Section section: sectionsList) {
        cout << "[" << section.getSectionId() << "]" << endl;
    }

    string id;
    cout << "ENTER YOUR PREFERRED SECTION ID -->";
    cin.ignore();
    getline(cin, id);

    for (int i = 0; i < sectionsList.size(); ++i) {
        if (sectionsList[i].getSectionId() == id) {
            sectionsList.erase(sectionsList.begin() + i);
            break;
        }
    }
}


void SectionOperation::ShowSection(vector<Section> & sectionsList) {
    int count = 1;
    for (Section &section: sectionsList) {
        cout << "  ***" << "\n SECTION " << count << "\n";
        cout << section.showSectionInformation() << endl;
        count++;
    }
}