//
// Created by trudbot on 2022/6/22.
//

#include "STUDENT_FRONT.h"

Student StudentInfoInput_Font(void){//学生信息输入
    Student stu = NewStudent();
    clean();
    printf("你现在正在添加学生信息\n");
    printf("请输入要添加的学生姓名: ");
    scanf("%s",stu->name);
    printf("请输入要添加的学生学号: ");
    scanf("%s",stu->id);
    printf("请输入要添加的学生专业: ");
    scanf("%s",stu->major);
    printf("请输入要添加的学生性别: ");
    scanf("%s",stu->gender);
    printf("请输入要添加的学生年龄: ");
    scanf("%d",&stu->age);
    printf("请输入要添加的学生绩点: ");
    scanf("%f",&stu->GPA);
    printf("\n");
    return stu;
}

boolean Check_Font(StuList head, Student stu){//添加学生信息， 并对是否成功添加作出反馈
    clean();
    if(AddStu(head, stu)){
        printf("学生信息已成功添加！");
        pause();
        return true;
    }
    else{
        ErrorPopUp("学号已存在， 学生信息添加失败！");
        return false;
    }
}

boolean IsContinueAdding(void){//
    return OptionalPopUp("是否继续添加学生信息");
}

void StudentDelete(char *id){
    clean();
    printf("你现在正在删除学生信息\n");
    printf("请输入你要删除学生的学号:");
    scanf("%s",id);
}

boolean Check_Del(StuList head, char* id){
    if(DelStu(head, id)){
        printf("学生信息已成功删除！");
        return true;
    }
    else{
        ErrorPopUp("未查找到该学生，学生信息删除失败！");
        return false;
    }
}

boolean IsContinueDel(void){//
    return OptionalPopUp("是否继续删除学生信息");
}

int submenu()
{
    clean();
    printf("—————————————————————\n");
	printf("|编 号|              功   能              |\n");
	printf("—————————————————————\n");
    printf("|  1  |         查看某个学生信息          |\n");
    printf("—————————————————————\n");
    printf("|  2  |         查看所有学生信息          |\n");
    printf("—————————————————————\n");
    printf("|  3  |        查看某性别学生信息         |\n");
    printf("—————————————————————\n");
    printf("|  4  |        查看某专业学生信息         |\n");
    printf("—————————————————————\n");
    printf("|  5  |   查看按学号排序后的所有学生信息  |\n");
    printf("—————————————————————\n");
    printf("|  6  |   查看按GPA排序后的所有学生信息   |\n");
    printf("—————————————————————\n");
    printf("请选择子菜单编号:");
    int item;
    scanf("%d",&item);
    return item;
}



void SelectQuery(int item,char *string){
    switch (item) {
        case 1:
            printf("请输入要查找的学生姓名：");
            scanf("%s",string);
            break;
        case 3:
            printf("请输入要查找的性别：");
            scanf("%s",string);
            break;
        case 4:
            printf("请输入要查找的专业：");
            scanf("%s", string);
            break;
        default:break;
    }
}


void Check_Query(){
    ErrorPopUp("未查找到此姓名的学生");
}

boolean IsContinueQuery(void){
    return OptionalPopUp("是否继续查找学生信息");
}

void Print( char string[20] , int outputlen)
{
    int n=strlen(string);
    int before = ( outputlen - n ) / 2;
    int after = outputlen - before - n;

    printf("|");
    int i;
    for(i=0;i<before;i++)
    {
        printf(" ");
    }
    printf("%s",string);
    for(i=0;i<after;i++)
    {
        printf(" ");
    }
}

void DisplayStudent(Student stu){//打印一个学生的信息
    char strAge[20],strGPA[20];
    printf("———————————————————————————————————————————\n");
    Print("姓名",18);
    Print("学号",18);
    Print("专业",18);
    Print("性别",8);
    Print("年龄",9);
    Print("GPA",8);
    printf("|\n");
    printf("———————————————————————————————————————————\n");
    Print(stu->name,18);
    Print(stu->id,18);
    Print(stu->major,18);
    Print(stu->gender,8);
    sprintf(strAge,"%d",stu->age);
    Print(strAge,9);
    sprintf(strGPA,"%.2f",stu->GPA);
    Print(strGPA,8);
    printf("|\n");
    printf("———————————————————————————————————————————\n");
}
void DisplayAllStudent(StuList head) {//打印一条链表上所有学生信息
	head = head->next;
    char strAge[20],strGPA[20];
    printf("———————————————————————————————————————————\n");
    Print("姓名",18);
    Print("学号",18);
    Print("专业",18);
    Print("性别",8);
    Print("年龄",9);
    Print("GPA",8);
    printf("|\n");
    while(head) {
        printf("———————————————————————————————————————————\n");
        Print(head->name,18);
        Print(head->id,18);
        Print(head->major,18);
        Print(head->gender,8);
        sprintf(strAge,"%d",head->age);
        Print(strAge,9);
        sprintf(strGPA,"%.2f",head->GPA);
        Print(strGPA,8);
        printf("|\n");
        head=head->next;
    }
    printf("———————————————————————————————————————————\n");
}

void Select(char *ID){
    printf("你现在正在更改学生信息\n");
    printf("请输入要修改的学生的学号:\n");
    scanf("%s", ID);
}

int  submenu1()
{
    printf("—————————————————\n");
	printf("|编 号|          功   能          |\n");
	printf("—————————————————\n");
    printf("|  1  |         修改姓名          |\n");
    printf("—————————————————\n");
    printf("|  2  |         修改学号          |\n");
    printf("—————————————————\n");
    printf("|  3  |         修改专业          |\n");
    printf("—————————————————\n");
    printf("|  4  |         修改性别          |\n");
    printf("—————————————————\n");
    printf("|  5  |         修改年龄          |\n");
    printf("—————————————————\n");
    printf("|  6  |         修改GPA           |\n");
    printf("—————————————————\n");
    printf("请选择子菜单编号:");
    int item;
    scanf("%d",&item);
    return item;
}

boolean Check_Update(Student stu){
    if(!stu){
        ErrorPopUp("未查找到该学号的学生");
        return false;
    }
    else
        return true;
}

void SelectUpdate(Student stu,int item){
    switch (item) {
        case 1:
            printf("请输入新的姓名:\n");
            scanf("%s", stu->name);
            break;
        case 2:
            printf("请输入新的学号：\n");
            scanf("%s", stu->id);
            break;
        case 3:
            printf("请输入新的专业：\n");
            scanf("%s", stu->major);
            break;
        case 4:
            printf("请输入新的性别：\n");
            scanf("%s", stu->gender);
            break;
        case 5:
            printf("请输入新的年龄：\n");
            scanf("%d", &stu->age);
            break;
        case 6:
            printf("请输入新的GPA：\n");
            scanf("%f", &stu->GPA);
            break;
        default:break;
    }
}

boolean IsContinueUpdate(void){
    return OptionalPopUp("是否继续更改当前学生信息");
}

