//
// Created by trudbot on 2022/6/22.
//

#include "ACCOUNT_FRONT.h"

Account AccountInfoInput_Font(void){//账号信息输入
    Account acc = NewAccount();
    clean();
    printf("你现在正在添加账号信息\n");
    printf("请输入要添加的用户名: ");
    scanf("%s",acc->accountName);
    printf("请输入您的密码: ");
    InputPassword(acc->password);
    printf("请输入用户状态: (学生请输入1，管理员输入2)");
    scanf("%d", &acc->userStatus);
    printf("\n");
    return acc;
}

bool Check_AddFont(AccountLink head, Account acc){//添加用户信息， 并对是否成功添加作出反馈
    if(AddAcc(head, acc)){
        printf("用户信息已成功添加！");
        pause();
        return true;
    }
    else{
        ErrorPopUp("用户名已存在， 用户信息添加失败！");
        pause();
        return false;
    }
}

bool IsContinueAddingAcc(void){//
    return OptionalPopUp("是否继续添加用户信息");
}

Account AccountInfoCancel_Font(void){
    Account acc = NewAccount();
    clean();
    printf("你现在正在删除账号信息\n");
    printf("请输入要删除的用户名: ");
    scanf("%s",acc->accountName);
    printf("请输入您的密码: ");
    InputPassword(acc->password);
    printf("请输入用户状态: (学生请输入1，管理员输入2)");
    scanf("%d",&acc->userStatus);
    printf("\n");
    return acc;
}

bool Check_CancelFont(AccountLink head, Account acc){//删除用户信息， 并对是否成功删除作出反馈
    if(DelAcc(head,acc)){
        printf("用户信息已成功删除！");
        pause();
        return true;
    }
    else{
        ErrorPopUp("用户不存在， 用户信息删除失败！");
        pause();
        return false;
    }
}

bool IsContinueCancelling(void){//
    return OptionalPopUp("是否继续删除用户信息");
}

Account AccountInfoUpdate_Font(void){
    Account acc = NewAccount();
    char newPassword[20];
    clean();
    printf("你现在正在更改账号密码\n");
    printf("请输入要更改的用户名: ");
    scanf("%s",acc->accountName);
    printf("请输入您的密码: ");
    InputPassword(acc->password);
    printf("\n");
    return acc;
}

bool Check_UpdateFont(AccountLink head, Account acc){
	Account temp = UpdateAcc(head, acc);
    if(temp){
        printf("请输入新密码:");
        InputPassword(temp->password);
        printf("密码更改成功!");
        pause();
        clean();
        return true; 
    }
    else{
        ErrorPopUp("用户不存在，无法更改密码！");
        pause();
        return false;
    }
}

bool IsContinueUpdating(void){
    return OptionalPopUp("是否继续更改用户信息");
}

