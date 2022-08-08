# include <stdio.h>
# include <stdlib.h>

typedef struct
{
    int top;//栈顶的索引
    int *data;//数据域
    int datalen;

}stack, *Stack;

Stack initstack(int maxlen)
{
    Stack p = (stack*)malloc(sizeof(stack));
    p->top = -1;
    p->data = (int *)malloc(sizeof(int)*maxlen);
    p->datalen = maxlen;
}

int IsEmpty(Stack p){
    return p->top == -1;
}

void push(Stack p, int elem){
    if(p->top == p->datalen-1){
        printf("栈已满， \"%d\" 入栈失败\n", elem);
        return;
    }
    p->data[++(p->top)] = elem;
}


int pop(Stack p){
    if(IsEmpty(p)){
        printf("\n栈是空的!\n");
        return -1;
    }
    return p->data[(p->top)--];
}

void MakeEmpty(Stack p){
    p->top = -1;

}

int main(void){
    Stack s = initstack(10);
    for(int i=0; i<12; i++)
        push(s, i+1);
    for(int i=0; i<11; i++)
        printf("%d ", pop(s)); 
}

