#ifndef CLION_TEST_TIME_H
#define CLION_TEST_TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time {

private:

    int _startHour;
    int _startMinute;

    int _sectionDuration;
    int _examDuration;

    int _finishHour = 0;
    int _finishMinute = 0;

public:

    Time(int startHour, int startMinute, int sectionDuration, int examDuration);

private:

    static bool isValidDuration(int duration);

    static bool isValidExamDuration(int duration);

public:

    int computeFinishTime();

private:

    int finishFirstState();

    int finishSecondState();

    int finishThirdState();

public:

    bool handleTimeInterference(Time &ob);

public:

    [[nodiscard]] string showSectionStartTime() const;

    [[nodiscard]] string showSectionDuration() const;

    string showSectionFinishTime();

    [[nodiscard]] int getStartHour() const;

    [[nodiscard]] int getStartMinute() const;

    [[nodiscard]] int getDuration() const;

    [[nodiscard]] int getExamDuration() const;

    [[nodiscard]] int getFinishHour() const;

    [[nodiscard]] int getFinishMinute() const;

};

#endif
