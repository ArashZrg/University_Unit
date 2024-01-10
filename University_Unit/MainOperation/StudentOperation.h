#ifndef UNIVERSITY_UNIT_STUDENTOPERATION_H
#define UNIVERSITY_UNIT_STUDENTOPERATION_H

#include <iostream>
#include <string>
#include "../People/Student.h"
#include <vector>

using namespace std;

class StudentOperation {
public:

    static void AddStudent(vector<Student> &studentsList , vector<int> &studentsNumbers);

    static void DeleteStudent(vector<Student> &studentsList);

    static void EditStudent(vector<Student> &studentsList);

    static void ShowStudents(vector<Student> &studentsList);

};


#endif //UNIVERSITY_UNIT_STUDENTOPERATION_H
