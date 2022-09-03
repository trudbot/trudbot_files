//
// Created by trudbot on 2022/6/22.
//

#include "LoginServlet.h"

boolean Login_Back(AccountLink head, Account user)
{
    int i;
    Welcome();
    for(i=1;i<=3;i++)
    {
		Login(user);
        if(!CheckAcc(head,user)){
            printf("账号或密码错误（还剩%d次机会）\n",3-i);
            pause();
            clean();
        }
        else{
            clean();
            return true;
        }
    }
    return false;
}
