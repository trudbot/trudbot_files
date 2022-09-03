//
// Created by trudbot on 2022/6/22.
//

#include "STUDENT_BLL.h"

boolean AddStu(StuList head, Student stu){
    if(CheckId(head,stu->id))
        return false;
    else{
        AddStudentNode(head,stu);
        return true;
    }
}

boolean DelStu(StuList head, char *id){
    return DelStudentById(head,id);
}

Student Query1(StuList head,char *string){
    Student stu;
    stu= ReturnStudentByName(head,string);
    return stu;
}

StuList Query2(StuList head,char *string){
    StuList tempList = StudentLinkOfGender(head, string);
    return tempList;
}

StuList Query3(StuList head,char *string){
    StuList tempList= StudentLinkOfMajor(head,string);
    return tempList;
}

void Query4(StuList head){
    SortByID(head);
}

void Query5(StuList head){
    SortByGPA(head);
}

Student ChangeStudent(StuList head,char *ID){
    Student stu;
    stu=ReturnStudentByID(head,ID);
    return stu;
}


