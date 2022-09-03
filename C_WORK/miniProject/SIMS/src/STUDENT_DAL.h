//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_STUDENT_ADT_H
#define SIMS_FINAL_VERSION_STUDENT_ADT_H
#include "STUDENT.h"
#include "COMMON.h"

void AddStudentNode(StuList head, Student stu); // 在链表上加上一个学生节点

void FreeLink(StuList head); //释放整个链表的内存

boolean CheckId(StuList head, char *id);//检查id是否已存在, 存在返回false, 否则true

void SortByID(StuList head);

void SortByGPA(StuList head);

StuList StudentLinkOfGender(StuList head, char* gender);

StuList StudentLinkOfMajor(StuList head, char* major);

boolean DelStudentByName(StuList head, char *name);//删除成功返回true，未找到对应学生返回false

boolean DelStudentById(StuList head, char *id);

Student ReturnStudentByName(StuList head, char* name);//返回学生结点的地址， 未找到则返回NULL

Student ReturnStudentByID(StuList head, char* id);

#endif //SIMS_FINAL_VERSION_STUDENT_ADT_H
