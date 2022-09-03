//
// Created by trudbot on 2022/6/22.
//

#include "COMMON.h"

//����������ʾ�� ����ϣ����ʾ����ʾ�ı�
void ErrorPopUp(char* text){
    MessageBox(NULL,text,NULL,MB_ICONERROR);
}

//����һ��ѡ�񵯴��� ѡ����"��"�򷵻�true, ���򷵻�false�������ַ�����Ϊ��ʾ�ı�
boolean OptionalPopUp(char* text){
    if(MessageBox(0,text,"��ʾ",  MB_YESNO|MB_ICONQUESTION) == IDNO)
        return false;
    else
        return true;
}

//���ڽ����û����������룬 �û������������Ϊ***�������ַ�������ȡ���롣
void InputPassword(char *password){
    int index = 0;
    char ch;
    ch = getch();
    while(ch){
        if(ch == 13 || index >= 100)
            break;
        else if(ch == '\b' && index != 0){
            printf("\b \b");
            index--;
        }
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            password[index++] = ch;
            printf("*");
        }
        ch = getch();
    }
    password[index] = '\0';
    printf("\n");
}

void clean(void){//����
    system("cls");
}

void pause(void){//��ͣ
    printf("\n");
    system("pause");
}

