//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_STU_BLL_H
#define SIMS_FINAL_VERSION_STU_BLL_H
#include "STUDENT_DAL.h"

boolean AddStu(StuList head, Student stu);

boolean DelStu(StuList head, char* id);

Student Query1(StuList head,char *string);

StuList Query2(StuList head,char *string);

StuList Query3(StuList head,char *string);

void Query4(StuList head);

void Query5(StuList head);

Student ChangeStudent(StuList head, char* ID);

#endif //SIMS_FINAL_VERSION_STU_BLL_H

