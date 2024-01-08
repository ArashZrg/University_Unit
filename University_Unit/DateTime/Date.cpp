#include "Date.h"
#include <string>

using namespace std;

Date::Date(int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum)
        : _yearOfSection(year), _monthOfSection(month), _dayOfSection(day),
          _yearOfExam(examYear), _monthOfExam(examMonth), _dayOfExam(examDay),
          _dayNum(dayNum) {}


string Date::showSectionStartDate()  {
    string result =
            "[" + to_string(_yearOfSection) + "/" + formatDate(_monthOfSection) + "/" + formatDate(_dayOfSection) + "]";
    return result;
}

string Date::showSectionExamDate()  {
    string result = "[" + to_string(_yearOfExam) + "/" + formatDate(_monthOfExam) + "/" + formatDate(_dayOfExam) + "]";
    return result;
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

int Date::getDayNum() const {
    return _dayNum;
}

bool Date::handleDayInterference(Date &ob) {

    bool isValid = true;

    if (_dayNum == ob._dayNum) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

bool Date::handleExamDayInterference(Date &ob) {
    bool isValid = true;

    if ((_yearOfExam == ob._yearOfExam) && (_monthOfExam == ob._monthOfExam) && (_dayOfExam == ob._dayOfExam)) {
        isValid = false;
        return isValid;
    } else {
        return isValid;
    }

}

int Date::getSectionYear() const {
    return _yearOfSection;
}

int Date::getSectionMonth() const {
    return _monthOfSection;
}

int Date::getSectionDay() const {
    return _dayOfSection;
}

int Date::getExamYear() const {
    return _yearOfExam;
}

int Date::getExamMonth() const {
    return _monthOfExam;
}

int Date::getExamDay() const {
    return _dayOfExam;
}