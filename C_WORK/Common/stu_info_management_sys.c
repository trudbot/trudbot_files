# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int Num = 100;

 typedef struct student
 {
     char name[20];
     int age;
     char id[12];
 }Student;

void format_print(Student *p);

void info_input(Student *p, int index, int oper_code);

void info_output(Student *p[], int index);

void multifunction(Student*p[], int index, int oper_code);

void Free(Student *p[], int index);

int main(void)
{
    Student** stu_list = (Student **)calloc(Num, sizeof(Student*));
    int index = 0;
    Student* p;
    char operation;

    while (1)
    {
        printf("请输入操作码!\n--------------------\n(A):录入学生信息\n(B):查询学生信息\n(C):打印所有学生信息\n(D):更改学生信息\n--------------------\n输入:");
        do
        {
            operation = getchar();
        } while (operation != 'A' 
        && operation != 'B'
        && operation != 'C' 
        && operation != 'D');
        printf("\n");

        switch (operation){

            case 'A':
                p = (Student*)malloc(sizeof(Student));
                info_input(p, index, 0);
                stu_list[index] = p;
                index++;
                break;
            case 'B':
                multifunction(stu_list, index, 0);
                break;
            case 'C':
                info_output(stu_list, index);
                break;
            case 'D':
                multifunction(stu_list, index, 1);
        }
        printf("是否继续操作:Y/N\n输入:");
        do
        {
            operation = getchar();
        } while (operation != 'Y' && operation != 'N');
        if (operation == 'N')
            break;
        printf("\n");
    }

    Free(stu_list, index);
    free(stu_list);
}

void info_input(Student *p, int index, int oper_code)
{
    if (index == Num)
    {    printf("存储空间已满!");
        return;
    }

    switch (oper_code){
        case 0:
            printf("---------学生信息录入-----------\n");
            break;
        case 1:
            printf("---------更新学生信息-----------\n");
    }

    printf("请输入学生姓名:");
    scanf("%s", &p->name);
    printf("\n");
    printf("请输入学生年龄:");
    scanf("%d", &p->age);
    printf("\n");
    printf("请输入学生学号:");
    scanf("%s", &p->id);
    printf("\n");

    switch (oper_code)
    {
    case 0:
        printf("信息录入成功!");
        break;
    
    case 1:
        printf("信息更改成功!");
        break;
    }

    printf("\n");
}

void info_output(Student *p[], int index)
{
    printf("********学生信息总览*********\n");

    for (int i=0; i<index; i++)
        format_print(p[i]);

    printf("****************************\n");
}

void format_print(Student *p)
{
    printf("-----\n");
    printf("姓名:%s\n", p->name);
    printf("年龄:%d\n", p->age);
    printf("学号:%s\n", p->id);
}

void Free(Student* p[], int index)
{
    for (int i=0; i<index; i++)
        free(p[i]);
}

void multifunction(Student*p[], int index, int oper_code)
{
    char name[10];
    int i;
    char operation;

    switch (oper_code){
    case 0:
        printf("****************学生信息查询*******************\n");
        break;
    case 1:
        printf("****************学生信息更改*******************\n");
        break;
    default:
        return;
    }

    while (1)
    {
        printf("请输入学生姓名:");
        scanf("%s", &name);
        printf("\n");

        for (i=0; i<index; i++)
        {
            if (strcmp(p[i]->name, name) == 0)
            {
                    format_print(p[i]);
                    if (oper_code == 1)
                        info_input(p[i], i, oper_code);
                    break;  
            }   
        }

        switch (oper_code)
        {
            case 0:
                printf("是否继续查询Y/N\n");
                break;
            case 1:
                printf("是否继续更改Y/N\n");
        }

        do{
            operation = getchar();
        }while(operation != 'Y' && operation != 'N');

        if (operation == 'N')
            break; 
    }

    printf("***********************************************\n");
}