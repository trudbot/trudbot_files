//
// Created by LingYunMu on 2022/5/8.
//
#include "AccountServlet.h"

void AddAccountServlet(AccountLink head){//addAccount��˲���
    Account acc;
    BeginAdd : acc = AccountInfoInput_Font();
    if(Check_AddFont(head, acc)){//���id�Ƿ��Ѵ���, ���ڷ���false, ����true
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
    if(Check_CancelFont(head, acc)){//����û��Ƿ�ɹ�ɾ��, �ɹ�����true
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
    if(Check_UpdateFont(head, acc)){//�ɹ�����true
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
