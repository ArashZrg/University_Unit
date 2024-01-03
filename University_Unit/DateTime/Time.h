#ifndef CLION_TEST_TIME_H
#define CLION_TEST_TIME_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Time {
private:
    int _startHour;
    int _startMinute;

    int _classDuration;
    int _examDuration;

    int _finishHour = 0;
    int _finishMinute = 0;
public:
    Time(int startHour, int startMinute, int classDuration, int examDuration);

    static bool isValidDuration(int durationHour);

    static bool isValidExamDuration(int examDuration);

    int computeFinishTime();

    int finishFirstState();

    int finishSecondState();

    int finishThirdState();

//    // Handling conflict class times
//    bool handleTimeInterference(Time &ob);

    string showClassStartTime() const;

    string showClassDuration() const;

    string showClassFinishTime();

    int getStartHour() const;

    int getStartMinute() const;

    int getDuration() const;

    int getExmaDuration() const;

    int getFinishHour() const;

    int getFinishMinute() const;

};


#endif
