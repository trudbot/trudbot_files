//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_STUDENT_BASE_H
#define SIMS_FINAL_VERSION_STUDENT_BASE_H
#include <stdlib.h>

struct student{
    char name[20];
    char id[20];
    char major[20];
    unsigned int age;
    char gender[10];
    float GPA;
    struct student* next;
};

typedef struct student student;
typedef struct student*  Student;
typedef Student StuList;

Student NewStudent(void);

#endif //SIMS_FINAL_VERSION_STUDENT_BASE_H

