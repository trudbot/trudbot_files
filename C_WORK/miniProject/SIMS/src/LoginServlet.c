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
            printf("�˺Ż�������󣨻�ʣ%d�λ��ᣩ\n",3-i);
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
