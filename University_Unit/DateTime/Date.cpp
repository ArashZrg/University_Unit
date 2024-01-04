#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date(int year, int month, int day, int examYear, int examMonth, int examDay, DaysOfWeek dayNum) : _yearOfSection(year),
                                                                                                 _monthOfSection(month),
                                                                                                 _dayOfSection(day),
                                                                                                 _yearOfExam(examYear),
                                                                                                 _monthOfExam(
                                                                                                         examMonth),
                                                                                                 _dayOfExam(examDay),
                                                                                                 _dayNum(dayNum) {}

string Date::showSectionStartDate() const {
    string result =
            "[" + to_string(_yearOfSection) + "/" + formatDate(_monthOfSection) + "/" + formatDate(_dayOfSection) + "]";
    return result;
}

string Date::showSectionExamDate() const {
    string result = "[" + to_string(_yearOfExam) + "/" + formatDate(_monthOfExam) + "/" + formatDate(_dayOfExam) + "]";
}

string Date::formatDate(int date) {
    string result;
    if (date < 10) {
        return result = "0" + to_string(date);
    } else {
        return result = to_string(date);
    }
}

string Date::showSectionDay(int dayNum) {
    switch (dayNum) {
        case 0 :
            return "Saturday";
        case 1:
            return "Sunday";
        case 2:
            return "Monday";
        case 3:
            return "Tuesday";
        case 4:
            return "Wednesday";
        case 5:
            return "Thursday";
        case 6:
            return "Friday";
        default:
            return "Invalid Day Of The Week!";
    }
}

DaysOfWeek Date::getDayNum() const {
    return _dayNum;
}