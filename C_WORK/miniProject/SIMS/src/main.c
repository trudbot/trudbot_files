#include "LoginServlet.h"
#include "AccountServlet.h"
#include "FILE.h"
#include "StudentServlet.h"
#include "Main_FRONT.h"

//admin 123456
//stu 123456 
int main(int argc, char *argv[]) {
	StuList stulist= StuInfoReading();
	AccountLink acclist= AccInfoReading();
	
	int item = AccountFunc();
	while(item != 2)
	{
		if(item == 1) AddAccountServlet(acclist);
		else if(item == 3) UpdateAccountServlet(acclist); 
		else if(item == 4) CancelAnAccount(acclist);
		item = AccountFunc();
	}
	
	Account user = NewAccount();
	if(!Login_Back(acclist, user))
	{
		LoginFailed();
		return 0;
	}
	
	int option = ChooseFunc(user);
	
	while(user->userStatus == ADMIN)
	{
		if(option == 1) 
			AddStudent(stulist);
		else if(option == 2)
			QueryStudent(stulist);
		else if(option == 3) 
			UpdateStudent(stulist);
		else if(option == 4) 
			DeleteStudent(stulist);
		else 
			goto NormalEnd;
		option = ChooseFunc(user);
	}
	
	while(user->userStatus == STU)
	{
		if(option == 1)
			QueryStudent(stulist);
		else 
			goto NormalEnd;
		option = ChooseFunc(user);
	}
	
	NormalEnd : 
	StuInfoWriting(stulist);
    AccInfoWriting(acclist);
	return 0;
}
