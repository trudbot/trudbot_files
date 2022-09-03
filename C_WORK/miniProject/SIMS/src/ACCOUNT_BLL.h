//
// Created by trudbot on 2022/5/6.
//

#ifndef SIMS_FINAL_VERSION_ACC_BLL_H
#define SIMS_FINAL_VERSION_ACC_BLL_H
#include "ACCOUNT_DAL.h"

boolean AddAcc(AccountLink head, Account acc);

boolean DelAcc(AccountLink head, Account acc);

boolean CheckAcc(AccountLink head, Account acc);

boolean FreeAcc(AccountLink head);

Account UpdateAcc(AccountLink head, Account acc);

#endif //SIMS_FINAL_VERSION_ACC_BLL_H
