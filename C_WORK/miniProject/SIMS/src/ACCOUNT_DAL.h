//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_ACCOUNT_ADT_H
#define SIMS_FINAL_VERSION_ACCOUNT_ADT_H
#include "ACCOUNT.h"
#include "COMMON.h"

boolean CheckAccountName(AccountLink head, Account acc);

Account ReturnAccount(AccountLink head, Account acc);

void AddAccountNode(AccountLink head, Account acc);

void FreeAccountLink(AccountLink head);

boolean CheckAccount(AccountLink head, Account userAcc);

void DelAccount(AccountLink head, char *accName);

void ChangeAccount(AccountLink head,Account acc, char* newPassword);

#endif //SIMS_FINAL_VERSION_ACCOUNT_ADT_H
