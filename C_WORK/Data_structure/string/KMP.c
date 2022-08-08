#include <stdio.h>
#include <string.h>
#define error -1

typedef unsigned int Index;


//回溯法暴力匹配
Index ViolentMatch(char *s, char *p){
    int slen = strlen(s);
    int plen = strlen(p);

    int sIndex = 0;
    int pIndex = 0;

    while(sIndex < slen && pIndex < plen){
        if(s[sIndex] == p[pIndex]){
            sIndex++;
            pIndex++;
        }else{
            sIndex = sIndex - pIndex + 1;
            pIndex = 0;
        }
    }
    if(pIndex == plen){
        return sIndex-pIndex;
    }else{
        return error;
    }
}




int main(void){

}