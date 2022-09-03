//
// Created by trudbot on 2022/6/22.
//

#include"FILE.h"

StuList StuInfoReading(void)
{
    StuList list = NewStudent();
    FILE* file = fopen("STUDENT_INFO.txt","r");
    if(file == NULL)
		return NULL; 
    int i = 1;
    while (1)
    {
        Student stu = NewStudent();
        i = fscanf(file, "%s%s%s%d%s%f",
                   stu->name,
                   stu->id,
                   stu->major,
                   &stu->age,
                   stu->gender,
                   &stu->GPA
        );
        if (i != EOF)
        {
            AddStudentNode(list, stu);
        }
        else{
        	free(stu);
        	break;
		}
    }
    fclose(file);
    return list;
}

void StuInfoWriting(StuList head)
{
    FILE* file = NULL;
    file = fopen("STUDENT_INFO.txt", "w");
    int i = 0;
    head = head->next;
    while (head != NULL)
    {
        fprintf(file, "%s %s %s %d %s %.2f\n",
                head->name,
                head->id,
                head->major,
                head->age,
                head->gender,
                head->GPA
        );
        head = head->next;
    }
    fclose(file);
}

AccountLink AccInfoReading(void)
{
    Account list = NewAccount();
    FILE* file = fopen("ACCOUNT_INFO.txt", "r");
    int i = 1;
    while (1)
    {
        Account acc = NewAccount();
        i = fscanf(file, "%s%s%d",
                   acc->accountName,
                   acc->password,
                   &acc->userStatus
        );
        if (i != EOF)
        {
            AddAccountNode(list, acc);
        }
        else{
        	free(acc);
        	break;
		}
    }
    fclose(file);
    return list;
}

void AccInfoWriting(AccountLink head)
{
    FILE* file = NULL;
    file = fopen("ACCOUNT_INFO.txt", "w");
    int i = 0;
    head = head->next;
    while (head != NULL)
    {
        fprintf(file, "%s %s %d\n",
                head->accountName,
                head->password,
                head->userStatus
        );
        head = head->next;
    }
    fclose(file);
}
