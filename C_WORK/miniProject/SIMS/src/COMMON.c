//
// Created by trudbot on 2022/6/22.
//

#include "COMMON.h"

//弹出错误提示， 传入希望显示的提示文本
void ErrorPopUp(char* text){
    MessageBox(NULL,text,NULL,MB_ICONERROR);
}

//弹出一个选择弹窗， 选择了"是"则返回true, 否则返回false。传入字符串作为显示文本
boolean OptionalPopUp(char* text){
    if(MessageBox(0,text,"提示",  MB_YESNO|MB_ICONQUESTION) == IDNO)
        return false;
    else
        return true;
}

//用于接收用户的密码输入， 用户的输入会隐藏为***。传入字符串来获取输入。
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

void clean(void){//清屏
    system("cls");
}

void pause(void){//暂停
    printf("\n");
    system("pause");
}

