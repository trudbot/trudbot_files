#ifndef SIMS_UI_ACCOUNT_FRONT
#define SIMS_UI_ACCOUNT_FRONT
#include "ACCOUNT_BLL.h"

Account AccountInfoInput_Font(void);

bool Check_AddFont(AccountLink head, Account acc);

bool IsContinueAddingAcc(void);

Account AccountInfoCancel_Font(void);

bool Check_CancelFont(AccountLink head, Account acc);

bool IsContinueCancelling(void);

Account AccountInfoUpdate_Font(void);

bool Check_UpdateFont(AccountLink head, Account acc);

bool IsContinueUpdating(void);

#endif //SIMS_UI_ACCOUNT_FRONT
