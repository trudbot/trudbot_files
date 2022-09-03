//
// Created by trudbot on 2022/6/22.
//

#include "ACCOUNT.h"

Account NewAccount(void){
    Account acc = (Account)malloc(sizeof (account));
    acc->next = NULL;
    return acc;
}


