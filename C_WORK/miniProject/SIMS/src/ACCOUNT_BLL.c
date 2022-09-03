//
// Created by trudbot on 2022/6/22.
//

#include "ACCOUNT_BLL.h"
boolean AddAcc(AccountLink head, Account acc){
    if(!CheckAccountName(head, acc)){
        return false;
    }
    else{
        AddAccountNode(head, acc);
        return true;
    }
}
boolean DelAcc(AccountLink head, Account acc){
    if(!CheckAccount(head,acc)){
        return  false;
    }
    else{
        DelAccount(head,acc->accountName);
        return true;
    }
}

boolean FreeAcc(AccountLink head){
    if(!head){
        return false;
    }
    else{
        FreeAccountLink(head);
        return true;
    }
}
boolean CheckAcc(AccountLink head, Account acc){
    if(CheckAccount(head,acc)){
        return true;
    }
    else{
        return false;
    }
}
Account UpdateAcc(AccountLink head, Account acc){
    return ReturnAccount(head, acc);
}


