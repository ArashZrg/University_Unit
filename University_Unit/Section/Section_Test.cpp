#include <iostream>
#include <string>
#include <vector>
#include "Section.h"

using namespace std;

int main() {
    Teacher teacher("Maryam" , "Lotfi");
    Location location("Fani Ghadim" , 2 , 15);
    Section section("AP001", "Advanced Programing", 1, 8, 30, 2, 3, 1402, 1, 5, 1402, 12, 25, 0);
    section.assignTeacher(&teacher);
    section.assignLocation(&location);
    cout <<section.getSectionId()<< endl;



}