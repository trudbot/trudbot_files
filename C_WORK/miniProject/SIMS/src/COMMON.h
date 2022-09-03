//
// Created by trudbot on 2022/6/22.
//

#ifndef SIMS_FINAL_VERSION_COMMON_BASE_H
#define SIMS_FINAL_VERSION_COMMON_BASE_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>

enum boolean{
    false=0, true
};

typedef enum boolean bool;

void ErrorPopUp(char* text);

boolean OptionalPopUp(char* text);

void InputPassword(char *password);

void clean(void);

void pause(void);

#endif //SIMS_FINAL_VERSION_COMMON_BASE_H
