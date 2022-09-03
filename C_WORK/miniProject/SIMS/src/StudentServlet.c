//
// Created by trudbot on 2022/6/22.
//

#include "StudentServlet.h"

void AddStudent(StuList head){//addStudentºó¶Ë²¿·Ö
    Student stu;
    BeginAdd : stu = StudentInfoInput_Font();
    if(Check_Font(head, stu)){
        if(IsContinueAdding()){
            goto BeginAdd;
        }
        else{
            return;
        }
    }
    else{
        goto BeginAdd;
    }
}

void DeleteStudent(StuList head){
    char id[20];
    BeginDel: StudentDelete(id);
    if(Check_Del(head, id)){
        if(IsContinueDel())
            goto BeginDel;
        else
            return ;
    }
    else
        goto BeginDel;
}

void QueryStudent(StuList head){
    int item;
    BeginQuery: item=submenu();
    char string[20];
    SelectQuery(item,string);
    switch(item){
        case 1:{
            Student stu;
            stu= Query1(head,string);
            if(stu)
                DisplayStudent(stu);
            else{
                Check_Query();
                goto BeginQuery;
            }
            break;
        }
        case 2:{
            DisplayAllStudent(head);
            break;
        }
        case 3:{
            StuList tempList;
            tempList= Query2(head,string);
            DisplayAllStudent(tempList);
            break;
        }
        case 4:{
            StuList tempList;
            tempList= Query3(head,string);
            DisplayAllStudent(tempList);
            break;
        }
        case 5:{
            Query4(head);
            DisplayAllStudent(head);
            break;
        }
        case 6:{
            Query5(head);
            DisplayAllStudent(head);
            break;
        }
        default:break;
    }
    pause();
    if(IsContinueQuery())
        goto BeginQuery;
}

void UpdateStudent(StuList head){
    char ID[20];
	BeginUpdate : Select(ID);
	Student stu =  ChangeStudent(head,ID);
    if(!Check_Update(stu))
        goto BeginUpdate;
    int item;
    clean();
    DisplayStudent(stu);
    select : item= submenu1();
    SelectUpdate(stu,item);
    if(IsContinueUpdate())
        goto select;
}

