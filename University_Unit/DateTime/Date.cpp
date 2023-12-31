#include "Date.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Date::Date(int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum) : _year(year),
                                                                                                 _month(month),
                                                                                                 _day(day),
                                                                                                 _examYear(examYear),
                                                                                                 _examMonth(examMonth),
                                                                                                 _examDay(examDay),
                                                                                                 _dayNum(dayNum) {}

string Date::showStartDateOfClass() {
    string result = to_string(_year) + "/" + formatDate(_month) + "/" + formatDate(_day);
    return result;
}

string Date::showExamDate() {
    string result = to_string(_examYear) + "/" + formatDate(_examMonth) + "/" + formatDate(_examDay);
}

string Date::formatDate(int date) {
    string result;
    if (date < 10) {
        return result = "0" + to_string(date);
    } else {
        return result = to_string(date);
    }
}

string Date::showDay(int dayNum) {
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