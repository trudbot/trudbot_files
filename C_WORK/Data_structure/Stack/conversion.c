#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 32
#define EMPTY -1

typedef enum{
    false = 0, true
}bool;

typedef struct{
    int data[STACKSIZE];
    int top;
}stack, *Stack;

Stack NewStack(void){
    Stack s = (Stack)malloc(sizeof(stack));
    s->top = EMPTY;
    return s;
}

bool IsEmpty(Stack s){
    return s->top == EMPTY;
}

bool push(Stack s, int value){
    if(s->top == STACKSIZE-1){
        return false;
    }
    else{
        s->data[++s->top] = value;
        return true;
    }
}

bool pop(Stack s){
    if(IsEmpty(s)){
        return false;
    }
    else{
        s->top--;
        return true;
    }
}

int getTop(Stack s){
    return s->data[s->top];
}

void Conversion(int num, int sys){
    Stack res = NewStack();
    int n = num;
    while(n != 0){
        push(res, n%sys);
        n /= sys;
    }
    printf("The %d-base form of %d is ", sys, num);
    while(!IsEmpty(res)){
        if(getTop(res) >= 10){
            printf("%c", getTop(res)-10+'A');
            pop(res);
        }
        else{
            printf("%d", getTop(res));
            pop(res);
        }
    }
    printf("\n");
}

int main(void){
    printf("请输入要转换的数:");
    int num;
    scanf("%d", &num);
    printf("请输入进制数:");
    int base;
    scanf("%d", &base);
    Conversion(num, base);
}
