#ifndef UNIVERSITY_UNIT_DATE_H
#define UNIVERSITY_UNIT_DATE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {

private:

    int _yearOfSection;
    int _monthOfSection;
    int _dayOfSection;
    int _yearOfExam;
    int _monthOfExam;
    int _dayOfExam;
    int _dayNum;

private:

    enum class DaysOfWeek {
        Saturday = 0,
        Sunday = 1,
        Monday = 2,
        Tuesday = 3,
        Wednesday = 4,
        Thursday = 5,
        Friday = 6
    };

public:

    Date(int year, int month, int day, int examYear, int examMonth, int examDay, int dayNum);

public:

    [[nodiscard]] string showSectionStartDate() const;

    [[nodiscard]] string showSectionExamDate() const;

    [[nodiscard]] int getDayNum() const;
private:

    static string formatDate(int date);

public:

    static string showSectionDay(int dayNum);

};

#endif
