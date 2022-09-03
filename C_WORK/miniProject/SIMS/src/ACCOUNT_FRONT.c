//
// Created by trudbot on 2022/6/22.
//

#include "ACCOUNT_FRONT.h"

Account AccountInfoInput_Font(void){//�˺���Ϣ����
    Account acc = NewAccount();
    clean();
    printf("��������������˺���Ϣ\n");
    printf("������Ҫ��ӵ��û���: ");
    scanf("%s",acc->accountName);
    printf("��������������: ");
    InputPassword(acc->password);
    printf("�������û�״̬: (ѧ��������1������Ա����2)");
    scanf("%d", &acc->userStatus);
    printf("\n");
    return acc;
}

bool Check_AddFont(AccountLink head, Account acc){//����û���Ϣ�� �����Ƿ�ɹ������������
    if(AddAcc(head, acc)){
        printf("�û���Ϣ�ѳɹ���ӣ�");
        pause();
        return true;
    }
    else{
        ErrorPopUp("�û����Ѵ��ڣ� �û���Ϣ���ʧ�ܣ�");
        pause();
        return false;
    }
}

bool IsContinueAddingAcc(void){//
    return OptionalPopUp("�Ƿ��������û���Ϣ");
}

Account AccountInfoCancel_Font(void){
    Account acc = NewAccount();
    clean();
    printf("����������ɾ���˺���Ϣ\n");
    printf("������Ҫɾ�����û���: ");
    scanf("%s",acc->accountName);
    printf("��������������: ");
    InputPassword(acc->password);
    printf("�������û�״̬: (ѧ��������1������Ա����2)");
    scanf("%d",&acc->userStatus);
    printf("\n");
    return acc;
}

bool Check_CancelFont(AccountLink head, Account acc){//ɾ���û���Ϣ�� �����Ƿ�ɹ�ɾ����������
    if(DelAcc(head,acc)){
        printf("�û���Ϣ�ѳɹ�ɾ����");
        pause();
        return true;
    }
    else{
        ErrorPopUp("�û������ڣ� �û���Ϣɾ��ʧ�ܣ�");
        pause();
        return false;
    }
}

bool IsContinueCancelling(void){//
    return OptionalPopUp("�Ƿ����ɾ���û���Ϣ");
}

Account AccountInfoUpdate_Font(void){
    Account acc = NewAccount();
    char newPassword[20];
    clean();
    printf("���������ڸ����˺�����\n");
    printf("������Ҫ���ĵ��û���: ");
    scanf("%s",acc->accountName);
    printf("��������������: ");
    InputPassword(acc->password);
    printf("\n");
    return acc;
}

bool Check_UpdateFont(AccountLink head, Account acc){
	Account temp = UpdateAcc(head, acc);
    if(temp){
        printf("������������:");
        InputPassword(temp->password);
        printf("������ĳɹ�!");
        pause();
        clean();
        return true; 
    }
    else{
        ErrorPopUp("�û������ڣ��޷��������룡");
        pause();
        return false;
    }
}

bool IsContinueUpdating(void){
    return OptionalPopUp("�Ƿ���������û���Ϣ");
}

