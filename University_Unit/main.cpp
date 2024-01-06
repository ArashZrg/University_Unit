#include <iostream>
#include <string>
#include <vector>
#include "DateTime/Time.h"
#include "DateTime/Date.h"
#include "Location/Location.h"
#include "People/Person.h"
#include "People/Teacher.h"
#include "People/Student.h"
#include "Section/Section.h"

using namespace std;

string whileMenu() {
    string result = string("      [Menu]\n")
                    + string(" *************** \n")
                    + string(" 1-SECTION \n")
                    + string(" 2-LOCATION \n")
                    + string(" 3-TEACHER \n")
                    + string(" 4-STUDENT \n")
                    + string(" 5-EXIT \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string locationMenu() {
    string result = string(" 1-ADD LOCATION \n")
                    + string(" 2-DELETE LOCATION \n")
                    + string(" 3-EDIT LOCATION \n")
                    + string(" 4-BACK TO MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

int main() {

    vector<Location> LOCATIONS;

    int OPTION = 0;


    while (OPTION != 5) {

        cout << whileMenu();
        cin >> OPTION;
        cout << "*************** \n";

        switch (OPTION) {
            case 1: {
                break;
            }

            case 2: {

                int locationOption;
                cout << locationMenu();
                cin >> locationOption;

                switch (locationOption) {
                    case 1: {
                        string facultyName;
                        cout << "ENTER FACULTY NAME: \n";
                        getline(cin, facultyName);

                        int floorNumber;
                        cout << "ENTER FLOOR NUMBER: \n";
                        cin >> floorNumber;

                        int classNumber;
                        cout << "ENTER CLASS NUMBER: \n";
                        cin >> classNumber;

                        Location location(facultyName, floorNumber, classNumber);
                        LOCATIONS.push_back(location);
                        break;
                    }
                    case 2: {
                        cout << "ID OF EXIST LOCATIONS : ";
                        for (Location l: LOCATIONS) {
                            cout << l.getLocationID() << " , ";
                        }
                        int number;
                        cout << '\n' << "WHICH LOCATION DO YOU WANT TO DELETE?";
                        cin >> number;
                        for (int i = 0; i < LOCATIONS.size(); ++i) {
                            if (LOCATIONS[i].getLocationID() == number) {
                                LOCATIONS.erase(LOCATIONS.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3:{
                        int locationId;
                        cout << "ENTER THE ID OF THE LOCATION TO EDIT: ";
                        cin >> locationId;

                        for(Location& loc : LOCATIONS){
                            if(loc.getLocationID() == locationId){
                                loc.editLocation();
                                break;
                            }
                        }
                        break;
                    }
                    case 4:{
                        break;
                    }
                }

                break;

            }

            case 3: {
                break;
            }

            case 4: {
                break;
            }

        }

    }
}
