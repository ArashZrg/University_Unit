//#include "Section.h"
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> Section::existingSectionIDs;
//
//Section::Section(string sectionId, string sectionName, bool projector, int year, int month, int day, int examYear,
//                 int examMonth,
//                 int examDay, int dayNum, int startHour, int startMinute, int classDuration, int examDuration) :
//        _sectionName(sectionName),
//        isNeedVideoProjector(projector),
//        date(year, month, day, examYear, examMonth, examDay, dayNum),
//        time(startHour, startMinute, classDuration, examDuration) {
//
//    if (isSectionIdValid(sectionId)) {
//        _sectionId = sectionId;
//        existingSectionIDs.push_back(sectionId);
//    } else {
//        throw invalid_argument("This ClassID Is Already Exist in System , Choose Another one !");
//    }
//}
//
//
//bool Section::isSectionIdValid(string sectionId) {
//    for (const string &existingId: existingSectionIDs) {
//        if (sectionId == existingId) {
//            return false;
//        }
//    }
//    return true;
//}
//
//string Section::getSectionId() {
//    return _sectionId;
//}
