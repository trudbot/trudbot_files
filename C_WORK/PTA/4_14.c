/*
4-14 十进制转换二进制 (15 分)
本题要求实现一个函数，将正整数n转换为二进制后输出。
*/

#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}

void dectobin( int n )
{
    if (n == 1 || n == 0)
    {
        printf("%d", n);
        return;
    }
    dectobin(n/2);
    printf("%d", n%2);
}