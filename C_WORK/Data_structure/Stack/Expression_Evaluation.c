//Created by 宋遗平 on 2022/05/09
//Topic : Expression Evaluation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STACKSIZE 100
#define EMPTY -1

typedef enum{
    false = 0, true
}bool;

typedef struct{
    int data[STACKSIZE];
    int top;
}stack, *Stack;

Stack NewStack(void){//初始化栈
    Stack s = (Stack)malloc(sizeof(stack));
    s->top = EMPTY;
    return s;//一开始忘记写return语句, 竟然也能正常运行, 后面才发现这个问题
    //原因是GCC编译器遇到这种情况会返回eax寄存器中的值， 在这里表现最后一次函数调用的返回值
    /*原文:This code has formally undefined behaviour, 
        and in practice it's calling convention and architecture dependent. 
        On one particular system, with one particular compiler, 
        the return value is the result of last expression evaluation, 
        stored in the eax register of that system's processor.
    link:
    https://stackoverflow.com/questions/1610030/why-does-flowing-off-the-end-of-a-non-void-function-without-returning-a-value-no
    */
}

bool push(Stack s, int value){//入栈
    if(s->top == STACKSIZE){
        return false;
    }
    else{
        s->data[++s->top] = value;
        return true;
    }
}

int pop(Stack s){//出栈
    if(s->top == EMPTY){
        return false;
    }
    else{
        return s->data[s->top--];
    }
}

int getTop(Stack s){//获取栈顶值
    if(s->top == EMPTY){
        return false;
    }
    else{
        return s->data[s->top];
    }
}

bool StackIsEmpty(Stack s){//判断栈是否为空
    return s->top == EMPTY;
}

int charToNum(char ch){
    return ch-'0';
}

bool IsNum(char ch){//判断字符是否是数字
    return ch >= '0' && ch <= '9';
}

int precedence(char ch){//获取运算符优先级
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '^'){
        return 3;
    }
    return false;
}

bool IsOperator(char ch){
    return ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch == '^';
}

int operate(int a, char op, int b){//计算
    switch(op){
        case '*' : return a*b;
        case '/' : return a/b;
        case '+' : return a+b;
        case '-' : return a-b;
        case '^' : return pow(a, b);
        default : return 0;
    }
}

int evaluate(char *tokens){//进行计算
    if(strlen(tokens) == 0){
        return 0;
    }
    Stack values = NewStack();//值栈
    Stack ops = NewStack();//操作符栈

    int n1, n2;//保存两个要进行计算的数
    char op;//保存运算的操作符
    char token;

    for(int i=0; i<strlen(tokens); i++){//读入表达式中的每一个字符
        token = tokens[i];

        if(token == ' '){
            continue;
        }

        if(IsNum(token)){//如果为数字, 直接压入值栈
            int value = 0;
            value = charToNum(token);
            while(IsNum(tokens[i+1])){
                i++;
                token = tokens[i];
                value = 10*value + charToNum(token);
            }
            push(values, value);
        }

        else if(token == '('){//如果为左括号, 直接压入值栈
            push(ops, token);
        }

        else if(token == ')'){//如果为右括号, 则取出括号内所有操作符进行计算
            while(getTop(ops) != '('){
                //执行一次运算的步骤
                /*
                1.取出栈顶操作符
                2.取出值栈中的两个运算数 
                3.将计算后的结果压入值栈中
                */
                op = pop(ops);
                n1 = pop(values);
                n2 = pop(values);
                push(values, operate(n2, op, n1));
            }
            pop(ops);//将左括号弹出
        }

        else{//为运算符时
            if(StackIsEmpty(ops)){//操作符栈空时直接入栈
                push(ops, token);
            }
            else{//不为空时, 若栈顶操作符的优先级大于或等于当前操作符的优先级, 弹出栈顶操作符进行运算
                //直到操作符栈为空或栈顶操作符优先级小于当前操作符时, 停止运算, 将当前操作符入栈
                while(!StackIsEmpty(ops) && precedence(token) <= precedence(getTop(ops))){
                    op = pop(ops);
                    n1 = pop(values);
                    n2 = pop(values);
                    push(values, operate(n2, op, n1));
                }
                push(ops, token);
            }
        }
    }

    while(!StackIsEmpty(ops)){//将栈中剩余的操作符取出进行计算
        op = pop(ops);
        n1 = pop(values);
        n2 = pop(values);
        push(values, operate(n2, op, n1));
    }
    int res = pop(values);
    free(ops);
    free(values);
    return res;
}

bool ExpIsValid(char *exp){
    char ch;
    //字符合法性
    for(int i=0; i<strlen(exp); i++){
        ch = exp[i];
        if(ch != ' ' && !IsNum(ch) && !IsOperator(ch) && ch != '(' && ch != ')'){
            return false;
        }
    }

    //括号匹配性检验
    Stack s = NewStack();
    for(int i=0; i<strlen(exp); i++){
        ch = exp[i];
        if(ch == '('){
            push(s, ch);
            continue;
        }
        if(ch == ')'){
            if(StackIsEmpty(s) || getTop(s) != '('){
                return false;
            }
            else{
                pop(s);
            }
        }
    }
    if(!StackIsEmpty(s)){
        return false;
    }
    return true;

}

int main(void){
    char expression[100];
    printf("\n"); 
    printf("Enter an expression:");
    gets(expression);
    if(!ExpIsValid(expression)){
        printf("表达式不合法， 程序已结束\n");
        return 0;
    }
    printf("The result is %d\n", evaluate(expression));
    return 0;
}
