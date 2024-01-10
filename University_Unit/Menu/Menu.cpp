#include "Menu.h"
#include <string>

string Menu::whileMenu() {
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

string Menu::sectionMenu() {
    string result = string(" 1-ADD SECTION \n")
                    + string(" 2-DELETE SECTION \n")
                    + string(" 3-EDIT SECTION \n")
                    + string(" 4-SHOW SECTION \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION ->");
    return result;
}

string Menu::interferenceMenu() {
    string result = string(" 1-CHANGE THE TIME AND TEACHER \n")
                    + string(" 2-CHANGE THE TIME , LOCATION AND DATE \n")
                    + string(" 3-CHANGE THE EXAM DATE\n")
                    + string(" 4-BACK \n")
                    + string(" CHOOSE OPTION ->");
    return result;
}


string Menu::locationMenu() {
    string result = string(" 1-ADD LOCATION \n")
                    + string(" 2-DELETE LOCATION \n")
                    + string(" 3-EDIT LOCATION \n")
                    + string(" 4-SHOW ALL LOCATION \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string Menu::teacherMenu() {
    string result = string(" 1-ADD TEACHER \n")
                    + string(" 2-DELETE TEACHER \n")
                    + string(" 3-EDIT TEACHER \n")
                    + string(" 4-SHOW ALL TEACHERS \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string(" CHOOSE OPTION -> ");
    return result;
}

string Menu::studentMenu() {
    string result = string(" 1-ADD STUDENT \n")
                    + string(" 2-DELETE STUDENT \n")
                    + string(" 3-EDIT STUDENT \n")
                    + string(" 4-SHOW ALL STUDENTS \n")
                    + string(" 5-BACK TO MAIN MENU \n")
                    + string("CHOOSE OPTION -> ");
    return result;
}