//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_STUDENT_ADT_H
#define SIMS_FINAL_VERSION_STUDENT_ADT_H
#include "STUDENT.h"
#include "COMMON.h"

void AddStudentNode(StuList head, Student stu); // �������ϼ���һ��ѧ���ڵ�

void FreeLink(StuList head); //�ͷ�����������ڴ�

boolean CheckId(StuList head, char *id);//���id�Ƿ��Ѵ���, ���ڷ���false, ����true

void SortByID(StuList head);

void SortByGPA(StuList head);

StuList StudentLinkOfGender(StuList head, char* gender);

StuList StudentLinkOfMajor(StuList head, char* major);

boolean DelStudentByName(StuList head, char *name);//ɾ���ɹ�����true��δ�ҵ���Ӧѧ������false

boolean DelStudentById(StuList head, char *id);

Student ReturnStudentByName(StuList head, char* name);//����ѧ�����ĵ�ַ�� δ�ҵ��򷵻�NULL

Student ReturnStudentByID(StuList head, char* id);

#endif //SIMS_FINAL_VERSION_STUDENT_ADT_H
