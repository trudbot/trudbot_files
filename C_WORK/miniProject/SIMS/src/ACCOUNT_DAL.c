//
// Created by trudbot on 2022/6/22.
//

#include "ACCOUNT_DAL.h"

boolean CheckAccountName(AccountLink head, Account acc)
{
	head = head->next;
	while(head)
	{
		if(strcmp(head->accountName, acc->accountName) == 0)
			return false;
		head = head->next;
	}
	return true;
}

boolean check(Account acc1, Account acc2)
{
	return strcmp(acc1->accountName, acc2->accountName)==0 && strcmp(acc2->password, acc1->password)==0;
}

void AddAccountNode(AccountLink head, Account acc)
{
    acc->next = head->next;
    head->next = acc;
}

void FreeAccountLink(AccountLink head)
{
    Account p;
    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

Account ReturnAccount(AccountLink head, Account acc)
{
	head = head->next;
	while(head)
	{
		if(check(head, acc))
			break;
		head = head->next;
	}
	return head;
}

boolean CheckAccount(AccountLink head, Account userAcc)
{
    Account p = head->next;
    while(p)
    {
    	if(strcmp(p->accountName, userAcc->accountName) == 0 && strcmp(p->password, userAcc->password) == 0)
    	{
    		userAcc->userStatus = p->userStatus;
    		return true;
		}
		p = p->next;
	}
	return false;
}

void DelAccount(AccountLink head, char* accName)
{
    Account p = head;
    while (p->next && strcmp(p->next->accountName, accName) != 0)
        p = p->next;
    Account s = p->next;
    p->next = p->next->next;
    free(s);
}

void ChangeAccount(AccountLink head,Account acc, char* newPassword)
{
    Account p = head->next;
    while (p && strcmp(p->accountName, acc->accountName) != 0 &&strcmp(p->password,acc->password)!=0)
    {
        p = p->next;
    }
    if(p == NULL)
    	return;
    strcpy(p->password, newPassword);
}

