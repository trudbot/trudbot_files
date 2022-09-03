//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_ACCOUNT_BASE_H
#define SIMS_FINAL_VERSION_ACCOUNT_BASE_H
#include <stdlib.h>

enum status{
    STU = 1, ADMIN
};

struct account{
    char accountName[20];
    char password[20];
    enum status userStatus;
    struct account* next;
};

typedef  struct account account;

typedef struct account* Account;

typedef Account AccountLink;

typedef enum status status;

Account NewAccount(void);

#endif //SIMS_FINAL_VERSION_ACCOUNT_BASE_H
