//#include "Location.h"
//
//Location::Location(string buidldingName, int roomNumber, int floorNumber, string buildingAddress) :
//        _buildingName(buidldingName), _roomNumberInEachFloor(roomNumber), _floorsNumber(floorNumber),
//        _buildingAddress(buildingAddress) {}
//
//
//string Location::getBuildingName() {
//    return _buildingName;
//}
//
//int Location::getRoomNumber() {
//    return _roomNumberInEachFloor;
//}
//
//int Location::getFloorNumber() {
//    return _floorsNumber;
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