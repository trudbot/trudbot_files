//
// Created by trudbot on 2022/6/22.
//

#include "STUDENT_FRONT.h"

Student StudentInfoInput_Font(void){//ѧ����Ϣ����
    Student stu = NewStudent();
    clean();
    printf("�������������ѧ����Ϣ\n");
    printf("������Ҫ��ӵ�ѧ������: ");
    scanf("%s",stu->name);
    printf("������Ҫ��ӵ�ѧ��ѧ��: ");
    scanf("%s",stu->id);
    printf("������Ҫ��ӵ�ѧ��רҵ: ");
    scanf("%s",stu->major);
    printf("������Ҫ��ӵ�ѧ���Ա�: ");
    scanf("%s",stu->gender);
    printf("������Ҫ��ӵ�ѧ������: ");
    scanf("%d",&stu->age);
    printf("������Ҫ��ӵ�ѧ������: ");
    scanf("%f",&stu->GPA);
    printf("\n");
    return stu;
}

boolean Check_Font(StuList head, Student stu){//���ѧ����Ϣ�� �����Ƿ�ɹ������������
    clean();
    if(AddStu(head, stu)){
        printf("ѧ����Ϣ�ѳɹ���ӣ�");
        pause();
        return true;
    }
    else{
        ErrorPopUp("ѧ���Ѵ��ڣ� ѧ����Ϣ���ʧ�ܣ�");
        return false;
    }
}

boolean IsContinueAdding(void){//
    return OptionalPopUp("�Ƿ�������ѧ����Ϣ");
}

void StudentDelete(char *id){
    clean();
    printf("����������ɾ��ѧ����Ϣ\n");
    printf("��������Ҫɾ��ѧ����ѧ��:");
    scanf("%s",id);
}

boolean Check_Del(StuList head, char* id){
    if(DelStu(head, id)){
        printf("ѧ����Ϣ�ѳɹ�ɾ����");
        return true;
    }
    else{
        ErrorPopUp("δ���ҵ���ѧ����ѧ����Ϣɾ��ʧ�ܣ�");
        return false;
    }
}

boolean IsContinueDel(void){//
    return OptionalPopUp("�Ƿ����ɾ��ѧ����Ϣ");
}

int submenu()
{
    clean();
    printf("������������������������������������������\n");
	printf("|�� ��|              ��   ��              |\n");
	printf("������������������������������������������\n");
    printf("|  1  |         �鿴ĳ��ѧ����Ϣ          |\n");
    printf("������������������������������������������\n");
    printf("|  2  |         �鿴����ѧ����Ϣ          |\n");
    printf("������������������������������������������\n");
    printf("|  3  |        �鿴ĳ�Ա�ѧ����Ϣ         |\n");
    printf("������������������������������������������\n");
    printf("|  4  |        �鿴ĳרҵѧ����Ϣ         |\n");
    printf("������������������������������������������\n");
    printf("|  5  |   �鿴��ѧ������������ѧ����Ϣ  |\n");
    printf("������������������������������������������\n");
    printf("|  6  |   �鿴��GPA����������ѧ����Ϣ   |\n");
    printf("������������������������������������������\n");
    printf("��ѡ���Ӳ˵����:");
    int item;
    scanf("%d",&item);
    return item;
}



void SelectQuery(int item,char *string){
    switch (item) {
        case 1:
            printf("������Ҫ���ҵ�ѧ��������");
            scanf("%s",string);
            break;
        case 3:
            printf("������Ҫ���ҵ��Ա�");
            scanf("%s",string);
            break;
        case 4:
            printf("������Ҫ���ҵ�רҵ��");
            scanf("%s", string);
            break;
        default:break;
    }
}


void Check_Query(){
    ErrorPopUp("δ���ҵ���������ѧ��");
}

boolean IsContinueQuery(void){
    return OptionalPopUp("�Ƿ��������ѧ����Ϣ");
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

void DisplayStudent(Student stu){//��ӡһ��ѧ������Ϣ
    char strAge[20],strGPA[20];
    printf("��������������������������������������������������������������������������������������\n");
    Print("����",18);
    Print("ѧ��",18);
    Print("רҵ",18);
    Print("�Ա�",8);
    Print("����",9);
    Print("GPA",8);
    printf("|\n");
    printf("��������������������������������������������������������������������������������������\n");
    Print(stu->name,18);
    Print(stu->id,18);
    Print(stu->major,18);
    Print(stu->gender,8);
    sprintf(strAge,"%d",stu->age);
    Print(strAge,9);
    sprintf(strGPA,"%.2f",stu->GPA);
    Print(strGPA,8);
    printf("|\n");
    printf("��������������������������������������������������������������������������������������\n");
}
void DisplayAllStudent(StuList head) {//��ӡһ������������ѧ����Ϣ
	head = head->next;
    char strAge[20],strGPA[20];
    printf("��������������������������������������������������������������������������������������\n");
    Print("����",18);
    Print("ѧ��",18);
    Print("רҵ",18);
    Print("�Ա�",8);
    Print("����",9);
    Print("GPA",8);
    printf("|\n");
    while(head) {
        printf("��������������������������������������������������������������������������������������\n");
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
    printf("��������������������������������������������������������������������������������������\n");
}

void Select(char *ID){
    printf("���������ڸ���ѧ����Ϣ\n");
    printf("������Ҫ�޸ĵ�ѧ����ѧ��:\n");
    scanf("%s", ID);
}

int  submenu1()
{
    printf("����������������������������������\n");
	printf("|�� ��|          ��   ��          |\n");
	printf("����������������������������������\n");
    printf("|  1  |         �޸�����          |\n");
    printf("����������������������������������\n");
    printf("|  2  |         �޸�ѧ��          |\n");
    printf("����������������������������������\n");
    printf("|  3  |         �޸�רҵ          |\n");
    printf("����������������������������������\n");
    printf("|  4  |         �޸��Ա�          |\n");
    printf("����������������������������������\n");
    printf("|  5  |         �޸�����          |\n");
    printf("����������������������������������\n");
    printf("|  6  |         �޸�GPA           |\n");
    printf("����������������������������������\n");
    printf("��ѡ���Ӳ˵����:");
    int item;
    scanf("%d",&item);
    return item;
}

boolean Check_Update(Student stu){
    if(!stu){
        ErrorPopUp("δ���ҵ���ѧ�ŵ�ѧ��");
        return false;
    }
    else
        return true;
}

void SelectUpdate(Student stu,int item){
    switch (item) {
        case 1:
            printf("�������µ�����:\n");
            scanf("%s", stu->name);
            break;
        case 2:
            printf("�������µ�ѧ�ţ�\n");
            scanf("%s", stu->id);
            break;
        case 3:
            printf("�������µ�רҵ��\n");
            scanf("%s", stu->major);
            break;
        case 4:
            printf("�������µ��Ա�\n");
            scanf("%s", stu->gender);
            break;
        case 5:
            printf("�������µ����䣺\n");
            scanf("%d", &stu->age);
            break;
        case 6:
            printf("�������µ�GPA��\n");
            scanf("%f", &stu->GPA);
            break;
        default:break;
    }
}

boolean IsContinueUpdate(void){
    return OptionalPopUp("�Ƿ�������ĵ�ǰѧ����Ϣ");
}

