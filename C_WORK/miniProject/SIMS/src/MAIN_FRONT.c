//
// Created by trudbot on 2022/6/22.
//

#include "Main_FRONT.h"

int AccountFunc( void ){
    clean();
    printf(" \n");
    printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
    printf("|                         SIMS狼由                       |\n");
    printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
    printf("|                    ***狼由孔嬬暇汽***                  |\n");
    printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
    printf("|         1.廣過嬲催          |        2.鞠遜狼由        |\n");
    printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
    printf("|         3.厚個畜鷹          |        4.廣??嬲薩        |\n");
    printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
    int item;
    printf("萩補秘僉??:");
    scanf("%d", &item);
    return item;
}

int ChooseFunc(Account user) {
	clean();
    if (user->userStatus == ADMIN) {
        printf(" \n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|                 僥伏佚連砿尖狼由?┨楡輳蔚烹?           |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|                    ***狼由孔嬬暇汽***                  |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|      1.奐紗僥伏佚連        |    2.臥儂僥伏佚連         |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|      3.俐個僥伏佚連        |    4.評茅僥伏佚連         |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|                     5.曜竃SIMS狼由                     |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
//        printf("|                     6.嬲薩譜崔                         |\n");
//        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("萩補秘1！！5參頼撹艇?詈杵峙長δ?\n");
    }
    else if (user->userStatus == STU) {
        printf(" \n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|                  僥伏佚連砿尖狼由??僥伏極??            |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|                    ***狼由孔嬬暇汽***                  |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("|      1.臥心僥伏佚連        |    2.曜竃佚連狼由         |\n");
        printf("|！！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
        printf("萩補秘1賜2參頼撹艇?詈杵峙長δ?\n");
    }
    printf("萩補秘:");
    int item;
    scanf("%d", &item);
    return item;
}

void LoginFailed(void){
    ErrorPopUp("鞠村払移肝方狛謹?? 狼由厮徭強曜竃");
    pause();
}


