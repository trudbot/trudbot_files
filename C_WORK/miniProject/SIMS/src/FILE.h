//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_FILE_H
#define SIMS_FINAL_VERSION_FILE_H
#include "ACCOUNT_DAL.h"
#include "STUDENT_DAL.h"

StuList StuInfoReading(void);

void StuInfoWriting(StuList head);

AccountLink AccInfoReading(void);

void AccInfoWriting(AccountLink head);

#endif //SIMS_FINAL_VERSION_FILE_H

