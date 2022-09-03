//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_LOGINSERVLET_H
#define SIMS_FINAL_VERSION_LOGINSERVLET_H
#include "ACCOUNT_BLL.h"
#include "Login_FRONT.h"

boolean Login_Back(AccountLink head, Account user);//返回值为是否登录成功， 传入的user存放用户的账户信息

#endif //SIMS_FINAL_VERSION_LOGINSERVLET_H
