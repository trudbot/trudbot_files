//
// Created by trudbot on 2022/6/22.
//
#include "STUDENT_DAL.h"

void AddStudentNode(StuList head, Student stu)// 在链表上加上一个学生节点
{
    stu->next=head->next;
    head->next=stu;
}

void FreeLink(StuList head)//释放整个链表的内存
{
    Student p;
    while(head){
    	p = head;
    	head = head->next;
    	free(p);
	}
}

boolean CheckId(StuList head, char *id)
{
    StuList P;
    P=head;
    while(P!=NULL && strcmp(P->id,id)!=0)
    {
        P=P->next;
    }
    if(P==NULL)
    {
        return false;
    }
    else
        return true;
}


void SortByID(StuList head)
{
    Student i=head->next;
    head->next=NULL;
    Student j,temp;

    while(i)
    {
        temp=i;
        i=i->next;
        j=head;
        while(j->next && strcmp(j->next->id,temp->id)>=0)
        {
            j=j->next;
        }
        temp->next=j->next;
        j->next=temp;
    }

}

void SortByGPA(StuList head)
{
    Student i=head->next;
    head->next=NULL;
    Student j,temp;

    while(i)
    {
        temp=i;
        i=i->next;
        j=head;
        while(j->next && j->next->GPA>=temp->GPA)
        {
            j=j->next;
        }
        temp->next=j->next;
        j->next=temp;
    }

}

StuList StudentLinkOfGender(StuList head, char* gender)
{
    StuList P,H;
    P=NewStudent();
    H=head;
    while(H!=NULL)
    {
        if(strcmp(H->gender,gender)==0)
        {
            Student J;
            J=NewStudent();
            strcpy(J->id, H->id);
            strcpy(J->name, H->name);
            J->GPA=H->GPA;
            J->age = H->age;
            strcpy(J->major, H->major);
            strcpy(J->gender, H->gender);
            AddStudentNode(P, J);
        }
        H=H->next;
    }
    return P;
}

StuList StudentLinkOfMajor(StuList head, char* major)
{
    StuList P,H;
    P=NewStudent();
    H=head->next;
    while(H != NULL)
    {
        if(strcmp(H->major,major)==0)
        {
            Student J;
            J=NewStudent();
            strcpy(J->id, H->id);
            strcpy(J->name, H->name);
            J->GPA=H->GPA;
            J->age = H->age;
            strcpy(J->major, H->major);
            strcpy(J->gender, H->gender);
            AddStudentNode(P, J);
        }
        H=H->next;
    }
    return P;
}

boolean DelStudentByName(StuList head, char *name)//删除成功返回true，未找到对应学生返回false
{
    Student target;
    while(head->next)
    {
    	if(strcmp(head->next->name, name) == 0)
    	{
    		target = head->next;
    		head->next = target->next;
    		free(target);
    		return true;
		}
		head = head->next;
	}
	return false;
}

boolean DelStudentById(StuList head, char *id)
{
    Student target;
    while(head->next)
    {
    	if(strcmp(head->next->id, id) == 0)
    	{
    		target = head->next;
    		head->next = target->next;
			free(target);
			return true; 
		}
		head = head->next;
	}
	return false;
}

Student ReturnStudentByName(StuList head, char* name)//返回学生结点的地址， 未找到则返回NULL
{
	head = head->next;
    while(head)
    {
    	if(strcmp(head->name, name) == 0)
    		return head;
    	head = head->next;
	}
	return NULL;
}

Student ReturnStudentByID(StuList head, char* id) {
    head = head->next;
    while(head)
    {
    	if(strcmp(head->id, id) == 0)
    		return head;
    	head = head->next;
	}
	return NULL;
}


