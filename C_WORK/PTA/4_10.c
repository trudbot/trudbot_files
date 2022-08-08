/*
4-10 递归求阶乘和 (15 分)
本题要求实现一个计算非负整数阶乘的简单函数，并利用该函数求 1!+2!+3!+...+n! 的值。
*/

#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));
        
    return 0;
}

double fact( int n )
{
    if (n == 1 || n==0)
        return 1;
    return n*fact(n-1);
}

double factsum( int n )
{
    if (n == 1)
        return 1;
    else if(n == 0)
        return 0;
    return fact(n) + factsum(n-1);
}
