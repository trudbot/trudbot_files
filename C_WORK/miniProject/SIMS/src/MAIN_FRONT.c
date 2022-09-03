//
// Created by trudbot on 2022/6/22.
//

#include "Main_FRONT.h"

int AccountFunc( void ){
    clean();
    printf(" \n");
    printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
    printf("|                         SIMSÏµÍ³                       |\n");
    printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
    printf("|                    ***ÏµÍ³¹¦ÄÜ²Ëµ¥***                  |\n");
    printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
    printf("|         1.×¢²áÕËºÅ          |        2.µÇÂ½ÏµÍ³        |\n");
    printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
    printf("|         3.¸ü¸ÄÃÜÂë          |        4.×¢ÏúÕË»§        |\n");
    printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
    int item;
    printf("ÇëÊäÈëÑ¡Ïî:");
    scanf("%d", &item);
    return item;
}

int ChooseFunc(Account user) {
	clean();
    if (user->userStatus == ADMIN) {
        printf(" \n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|                 Ñ§ÉúÐÅÏ¢¹ÜÀíÏµÍ³£¨¹ÜÀíÔ±¶Ë£©           |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|                    ***ÏµÍ³¹¦ÄÜ²Ëµ¥***                  |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|      1.Ôö¼ÓÑ§ÉúÐÅÏ¢        |    2.²éÑ¯Ñ§ÉúÐÅÏ¢         |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|      3.ÐÞ¸ÄÑ§ÉúÐÅÏ¢        |    4.É¾³ýÑ§ÉúÐÅÏ¢         |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|                     5.ÍË³öSIMSÏµÍ³                     |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
//        printf("|                     6.ÕË»§ÉèÖÃ                         |\n");
//        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("ÇëÊäÈë1¡ª¡ª5ÒÔÍê³ÉÄúÏëÊµÏÖµÄ¹¦ÄÜ\n");
    }
    else if (user->userStatus == STU) {
        printf(" \n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|                  Ñ§ÉúÐÅÏ¢¹ÜÀíÏµÍ³£¨Ñ§Éú¶Ë£©            |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|                    ***ÏµÍ³¹¦ÄÜ²Ëµ¥***                  |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("|      1.²é¿´Ñ§ÉúÐÅÏ¢        |    2.ÍË³öÐÅÏ¢ÏµÍ³         |\n");
        printf("|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
        printf("ÇëÊäÈë1»ò2ÒÔÍê³ÉÄúÏëÊµÏÖµÄ¹¦ÄÜ\n");
    }
    printf("ÇëÊäÈë:");
    int item;
    scanf("%d", &item);
    return item;
}

void LoginFailed(void){
    ErrorPopUp("µÇÂ¼Ê§°Ü´ÎÊý¹ý¶à£¬ ÏµÍ³ÒÑ×Ô¶¯ÍË³ö");
    pause();
}


