//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_STUDENT_FRONT_H
#define SIMS_STUDENT_FRONT_H
#include "STUDENT_BLL.h"

Student StudentInfoInput_Font(void);

boolean Check_Font(StuList head, Student stu);

boolean IsContinueAdding(void);

void StudentDelete(char *id);

boolean Check_Del(StuList head, char* id);

boolean IsContinueDel(void);

int submenu();

void DisplayStudent(Student stu);

void DisplayAllStudent(StuList head);

void SelectQuery(int item,char *string);

void Check_Query();

boolean IsContinueQuery(void);

void Select(char *ID);

int submenu1();

void SelectUpdate(Student stu,int item);

boolean IsContinueUpdate(void);

boolean Check_Update(Student stu);

#endif //SIMS_STUDENT_FRONT_H

