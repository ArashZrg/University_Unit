////
//// Created by Arash on 12/24/2023.
////
//
//#include "Time.h"
//
////DONE
//Time::Time(int startHour, int startMinute, int duration, int examDuration) : _startHour(startHour),
//                                                                             _startMinute(startMinute) {
//    if (isValidDuration(duration)) {
//        _duration = duration;
//    } else {
//        throw invalid_argument("Time of Class Section most be between 1 or 3 hour");
//    }
//
//    if (isValidExamDuration(examDuration)) {
//        _examDuration = examDuration;
//    } else {
//        throw invalid_argument("Time of Test most be between 2 or 3 hour");
//    }
//}
//
////DONE
//bool Time::isValidExamDuration(int examDuration) {
//    bool isValid = true;
//
//    if (examDuration < 2 || examDuration > 3) {
//        isValid = false;
//        return isValid;
//    }
//
//    return isValid;
//}
//
////DONE
//bool Time::isValidDuration(int durationHour) {
//    bool isValid = true;
//
//    if (durationHour < 1 || durationHour > 3) {
//        isValid = false;
//        return isValid;
//    }
//
//    return isValid;
//}
//
////DONE
//string Time::showClassStartTime() const {
//    if (_startMinute >= 0 && _startMinute <= 9) {
//        string result = "[Start-> Hour:" + to_string(_startHour) + " , Minute:0" + to_string(_startMinute) + "]";
//        return result;
//    } else {
//        string result = "[Start-> Hour:" + to_string(_startHour) + " , Minute:" + to_string(_startMinute) + "]";
//        return result;
//    }
//}
//
////DONE
//string Time::showClassDuration() const {
//    string result = "[Duration-> Hour:" + to_string(_duration) + " , Minute:00]";
//    return result;
//}
//
////Done
//int Time::getDuration() const {
//    return _duration;
//}
//
////Done
//int Time::getStartHour() const {
//    return _startHour;
//}
//
////Done
//int Time::getStartMinute() const {
//    return _startMinute;
//}
//
////DONE
//int Time::getExmaDuration() const {
//    return _examDuration;
//}
//
////DONE
//int Time::getFinishHour() const {
//    return _finishHour;
//}
//
////DONE
//int Time::getFinishMinute() const {
//    return _finishMinute;
//}
//
//////DONE
////int Time::computeFinishTime() {
////    if (_duration == 1) {
////        return finishFirstState();
////    } else if (_duration == 2) {
////        return finishSecondState();
////    } else if (_duration == 3) {
////        return finishThirdState();
////    }
////
////}
//
////DONE
//int Time::finishFirstState() {
//    int result = 0;
//
//    _finishMinute = _startMinute + 50;
//    _finishHour = _startHour;
//
//    if (_finishMinute >= 60) {
//        _finishHour = (_finishHour + 1) * 60;
//        _finishHour -= 60;
//        result = _finishHour + _finishMinute;
//        return result;
//    } else {
//        result = (_finishHour * 60) + _finishMinute;
//        return result;
//    }
//
//}
//
////DONE
//int Time::finishSecondState() {
//    int result = 0;
//    _finishMinute = _startMinute + 30;
//    _finishHour = _startHour + 1;
//
//    if (_finishMinute >= 60) {
//        _finishHour = (_finishHour + 1) * 60;
//        _finishHour -= 60;
//        result = _finishHour + _finishMinute;
//        return result;
//    } else {
//        result = (_finishHour * 60) + _finishMinute;
//        return result;
//    }
//}
//
////DONE
//int Time::finishThirdState() {
//    int result = 0;
//    _finishMinute = _startMinute + 20;
//    _finishHour = _startHour + 2;
//
//    if (_finishMinute >= 60) {
//        _finishHour = (_finishHour + 1) * 60;
//        _finishHour -= 60;
//        result = _finishHour + _finishMinute;
//        return result;
//    } else {
//        result = (_finishHour * 60) + _finishMinute;
//        return result;
//    }
//}
//
////DONE
//void Time::showClassFinishTime() {
//    int hour = computeFinishTime() / 60;
//    int minute = computeFinishTime() % 60;
//    cout << "[Finish At-> Hour: " << hour << ", Minute: " << minute << "]";
//}
//
//
////bool Time::handleTimeInterference(Time &ob) {
////    bool isValid = true;
////    if (ob._startHour >= _startHour && ob.computeFinishTime() <= this->computeFinishTime()) {
////        isValid = false;
////        isValid;
////    } else {
////        return isValid;
////    }
//
