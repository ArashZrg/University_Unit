#include <iostream>
#include <string>
#include "Time.h"

Time::Time(int startHour, int startMinute, int sectionDuration, int examDuration)
        : _startHour(startHour),
          _startMinute(startMinute) {
    if (isValidDuration(sectionDuration)) {
        _sectionDuration = sectionDuration;
    } else {
        throw invalid_argument("Time Of Section Most Be (1 , 2 Or 3) Hour!");
    }

    if (isValidExamDuration(examDuration)) {
        _examDuration = examDuration;
    } else {
        throw invalid_argument("Time Of Test Most Be (2 Or 3) Hour");
    }
}

bool Time::isValidDuration(int duration) {
    bool isValid = true;

    if (duration < 1 || duration > 3) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

bool Time::isValidExamDuration(int duration) {
    bool isValid = true;

    if (!(duration == 2 || duration == 3)) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

int Time::computeFinishTime() {
    int result = 0;
    if (_sectionDuration == 1) {
        result = finishFirstState();
    } else if (_sectionDuration == 2) {
        result = finishSecondState();
    } else if (_sectionDuration == 3) {
        result = finishThirdState();
    }
    return result;
}

int Time::finishFirstState() {
    int result = 0;

    _finishMinute = _startMinute + 50;
    _finishHour = _startHour;

    if (_finishMinute >= 60) {
        _finishHour = (_finishHour + 1) * 60;
        _finishMinute -= 60;
        result = _finishHour + _finishMinute;
        return result;
    } else {
        result = (_finishHour * 60) + _finishMinute;
        return result;
    }

}

int Time::finishSecondState() {
    int result = 0;
    _finishMinute = _startMinute + 30;
    _finishHour = _startHour + 1;

    if (_finishMinute >= 60) {
        _finishHour = (_finishHour + 1) * 60;
        _finishMinute -= 60;
        result = _finishHour + _finishMinute;
        return result;
    } else {
        result = (_finishHour * 60) + _finishMinute;
        return result;
    }
}

int Time::finishThirdState() {
    int result = 0;
    _finishMinute = _startMinute + 20;
    _finishHour = _startHour + 2;

    if (_finishMinute >= 60) {
        _finishHour = (_finishHour + 1) * 60;
        _finishMinute -= 60;
        result = _finishHour + _finishMinute;
        return result;
    } else {
        result = (_finishHour * 60) + _finishMinute;
        return result;
    }
}

bool Time::handleTimeInterference(Time &ob) {
    bool isValid = true;
    if (ob._startHour >= _startHour && ob.computeFinishTime() <= this->computeFinishTime()) {
        isValid = false;
        return isValid;
    } else if (ob._startHour <= _startHour && this->computeFinishTime() <= ob.computeFinishTime()) {
        isValid = false;
    } else {
        return isValid;
    }
    return isValid;
}

string Time::showSectionStartTime() const {
    if (_startMinute >= 0 && _startMinute <= 9) {
        string result = "[Start-> Hour:" + to_string(_startHour) + " , Minute:0" + to_string(_startMinute) + "]";
        return result;
    } else {
        string result = "[Start-> Hour:" + to_string(_startHour) + " , Minute:" + to_string(_startMinute) + "]";
        return result;
    }
}

string Time::showSectionDuration() const {
    string result = "[Duration-> Hour:" + to_string(_sectionDuration) + " , Minute:00]";
    return result;
}

string Time::showSectionFinishTime() {
    int hour = computeFinishTime() / 60;
    int minute = computeFinishTime() % 60;
    string result = "[Finish At-> Hour: " + to_string(hour) + ", Minute: " + to_string(minute) + "]";
    return result;
}

int Time::getStartHour() const {
    return _startHour;
}

int Time::getStartMinute() const {
    return _startMinute;
}

int Time::getDuration() const {
    return _sectionDuration;
}

int Time::getExamDuration() const {
    return _examDuration;
}

int Time::getFinishHour() const {
    return _finishHour;
}

int Time::getFinishMinute() const {
    return _finishMinute;
}

void Time::setStartHour(int hour) {
    _startHour = hour;
}

void Time::setStartMinute(int minute) {
    _startMinute = minute;
}


