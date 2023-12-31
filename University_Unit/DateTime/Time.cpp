#include "Time.h"


Time::Time(int startHour, int startMinute, int classDuration, int examDuration) : _startHour(startHour),


                                                                                  _startMinute(startMinute) {
    if (isValidDuration(classDuration)) {
        _classDuration = classDuration;
    } else {
        throw invalid_argument("Time Of Section Most Be Between 1 Or 3 Hour!");
    }

    if (isValidExamDuration(examDuration)) {
        _examDuration = examDuration;
    } else {
        throw invalid_argument("Time Of Test Most Be Between 2 Or 3 Hour");
    }
}

bool Time::isValidDuration(int durationHour) {
    bool isValid = true;

    if (durationHour < 1 || durationHour > 3) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

bool Time::isValidExamDuration(int examDuration) {
    bool isValid = true;

    if (!(examDuration == 2 || examDuration == 3)) {
        isValid = false;
        return isValid;
    }

    return isValid;
}

int Time::computeFinishTime() {
    if (_classDuration == 1) {
        return finishFirstState();
    } else if (_classDuration == 2) {
        return finishSecondState();
    } else if (_classDuration == 3) {
        return finishThirdState();
    }

}

int Time::finishFirstState() {
    int result = 0;

    _finishMinute = _startMinute + 50;
    _finishHour = _startHour;

    if (_finishMinute >= 60) {
        _finishHour = (_finishHour + 1) * 60;
        _finishHour -= 60;
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
        _finishHour -= 60;
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
        _finishHour -= 60;
        result = _finishHour + _finishMinute;
        return result;
    } else {
        result = (_finishHour * 60) + _finishMinute;
        return result;
    }
}

//bool Time::handleTimeInterference(Time &ob) {
//    bool isValid = true;
//    if (ob._startHour >= _startHour && ob.computeFinishTime() <= this->computeFinishTime()) {
//        isValid = false;
//        isValid;
//    } else {
//        return isValid;
//    }
//
//}

string Time::showClassStartTime() const {
    if (_startMinute >= 0 && _startMinute <= 9) {
        string result = "[Start-> Hour:" + to_string(_startHour) + " , Minute:0" + to_string(_startMinute) + "]";
        return result;
    } else {
        string result = "[Start-> Hour:" + to_string(_startHour) + " , Minute:" + to_string(_startMinute) + "]";
        return result;
    }
}

string Time::showClassDuration() const {
    string result = "[Duration-> Hour:" + to_string(_classDuration) + " , Minute:00]";
    return result;
}

string Time::showClassFinishTime() {
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
    return _classDuration;
}

int Time::getExmaDuration() const {
    return _examDuration;
}

int Time::getFinishHour() const {
    return _finishHour;
}

int Time::getFinishMinute() const {
    return _finishMinute;
}
