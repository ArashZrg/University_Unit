//#include "Location.h"
//
//Location::Location(string buidldingName, int roomNumber, int floorNumber, string buildingAddress) :
//        _facultyName(buidldingName), _roomNumberInEachFloor(roomNumber), _floorNumber(floorNumber),
//        _buildingAddress(buildingAddress) {}
//
//
//string Location::getBuildingName() {
//    return _facultyName;
//}
//
//int Location::getRoomNumber() {
//    return _roomNumberInEachFloor;
//}
//
//int Location::getFloorNumber() {
//    return _floorNumber;
//}
//
//string Location::getBuildingAddress() {
//    return _buildingAddress;
//}
//
//
//string Location::showBuildingInformation() {
//    string result = "[Name: " + getBuildingName() + "]\n" +
//                    "[Count Of Rooms : " + to_string(getRoomNumber()) + "]\n" +
//                    "[Count Of Floors : " + to_string(getFloorNumber()) + "]\n" +
//                    "[Address -> " + getBuildingAddress() + "]\n";
//    return result;
//}