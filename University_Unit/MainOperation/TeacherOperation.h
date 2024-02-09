//
// Created by Arash on 1/10/2024.
//

#ifndef UNIVERSITY_UNIT_TEACHEROPERATION_H
#define UNIVERSITY_UNIT_TEACHEROPERATION_H


#include "../People/Teacher.h"
#include <vector>

class TeacherOperation {
public:
    static void AddTeacher(vector<Teacher> &teachersList);
    static void DeleteTeacher(vector<Teacher> &teachersList);
    static void EditTeacher(vector<Teacher> &teachersList);
    static void ShowTeacher(vector<Teacher> &teachersList);


};


#endif //UNIVERSITY_UNIT_TEACHEROPERATION_H
