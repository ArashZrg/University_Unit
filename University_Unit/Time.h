//
// Created by Arash on 12/24/2023.
//

#ifndef CLION_TEST_TIME_H
#define CLION_TEST_TIME_H

#include <iostream>
#include <string>


using namespace std;

class Time {
private:
    int _startHour;
    int _startMinute;

    int _duration;
    int _examDuration;

    int _finishHour = 0;
    int _finishMinute = 0;
public:

    //Constructor for set the
    //Start Hour and Minute
    //Duration of Class
    //Duration of Exam
    // constructor DONE (\OK\)
    Time(int startHour, int startMinute, int duration, int examDuration);

    // To validate the duration of class
    // Func DONE (\OK\)
    static bool isValidExamDuration(int examDuration);

    // To validate the duration of class (OK)
    // Func DONE (\OK\)
    static bool isValidDuration(int durationHour);


    // Show Class Start Time (OK)
    // Func DONE (\OK\)
    string showClassStartTime() const;

    //Show Class Duration Time
    // Func DONE (\OK\)
    string showClassDuration() const;

    //Show finish Time
    // Func DONE (\OK\)
    void showClassFinishTime();

    //Compute Finish Time of Class
    // Func DONE (\OK\)
    int computeFinishTime();

    // Func DONE (\OK\)
    int finishFirstState();

    // Func DONE (\OK\)
    int finishSecondState();

    // Func DONE (\OK\)
    int finishThirdState();


    //get Exam Duration
    // Func DONE (\OK\)
    int getExmaDuration() const;


    //get Finish Hour
    // Func DONE (\OK\)
    int getFinishHour() const;


    //get finish Minute
    // Func DONE (\OK\)
    int getFinishMinute() const;


    // get Duration
    // Func DONE (\OK\)
    int getDuration() const;


    //get Hour
    // Func DONE (\OK\)
    int getStartHour() const;


    //get Minute
    // Func DONE (\OK\)
    int getStartMinute() const;



//    // Handling interfrence class times
//    bool handleTimeInterference(Time &ob);

};


#endif //CLION_TEST_TIME_H
