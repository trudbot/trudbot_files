//
// Created by trudbot on 2022/6/22.
//

#include "STUDENT.h"

Student NewStudent(void){
    Student stu = (Student)malloc(sizeof (student));
    stu->next = NULL;
    return stu;
}
