#ifndef CLION_TEST_TIME_H
#define CLION_TEST_TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time {

private:

//private fields
    int _startHour;
    int _startMinute;

    int _sectionDuration;
    int _examDuration;

    int _finishHour = 0;
    int _finishMinute = 0;

public:

//Constructor
    Time(int startHour, int startMinute, int sectionDuration, int examDuration);

public:

// Functions for validating duration and exam duration
// for section duration , it most be 1 , 2 or 3 hour
// and exam duration most be 2 or 3 hour
    static bool isValidDuration(int duration);

    static bool isValidExamDuration(int duration);

private:

// for compute the Finish time of class , i write it base on duration and start time
    int computeFinishTime();

// for when duration is 1 hour i have finishFirstState()
    int finishFirstState();

// for when duration is 2 hour i have finishSecondState()
    int finishSecondState();

// for when duration is 3 hour i have finishThirdState()
    int finishThirdState();

public:

    //And this Function handel the interference of two Section
    // Use in Section Class
    bool handleTimeInterference(Time &ob);

public:

    [[nodiscard]] string showSectionStartTime() const;

    [[nodiscard]] string showSectionDuration() const;

    string showSectionFinishTime();


    //Getters
    [[nodiscard]] int getStartHour() const;

    [[nodiscard]] int getStartMinute() const;

    [[nodiscard]] int getDuration() const;

    [[nodiscard]] int getExamDuration() const;

    [[nodiscard]] int getFinishHour() const;

    [[nodiscard]] int getFinishMinute() const;

public:
    //setters
    void setStartHour(int hour);

    void setStartMinute(int minute);

    void setSectionDuration(int sectionDuration);

    void setExamDuration(int examDuration);
};

#endif
