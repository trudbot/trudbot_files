//
// Created by LingYunMu on 2022/5/8.
//
#include "AccountServlet.h"

void AddAccountServlet(AccountLink head){//addAccount后端部分
    Account acc;
    BeginAdd : acc = AccountInfoInput_Font();
    if(Check_AddFont(head, acc)){//检查id是否已存在, 存在返回false, 否则true
        if(IsContinueAddingAcc()){
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

void CancelAnAccount( AccountLink head ){
    Account acc;
    BeginCancel : acc = AccountInfoCancel_Font();
    if(Check_CancelFont(head, acc)){//检查用户是否成功删除, 成功返回true
        if(IsContinueCancelling()){
            goto BeginCancel;
        }
        else{
            return;
        }
    }
    else{
        goto BeginCancel;
    }
}

void UpdateAccountServlet( AccountLink head ){
    Account acc;
    char newPassword[20];
    BeginUpdate : acc = AccountInfoUpdate_Font();
    if(Check_UpdateFont(head, acc)){//成功更改true
        if(IsContinueUpdating()){
            goto BeginUpdate;
        }
        else{
            return;
        }
    }
    else{
        goto BeginUpdate;
    }
}
