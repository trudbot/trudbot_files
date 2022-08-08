/*
数列求和-加强版 (20 分)

给定某数字A（1≤A≤9）以及非负整数N（0<N≤100000），求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。例如A=1, N=3时，S=1+11+111=123。

输入格式：
输入数字A与非负整数N。

输出格式：
输出其N项数列之和S的值。

输入样例：
1 3
输出样例：
123

注意：结果可能超出整型范围
*/

# include <stdio.h>

int main(void)
{
    int A, N, temp;
    scanf("%d %d", &A, &N);

    int res[N+1];//用数组保存结果， 避免溢出的问题

    for(int i=0; i<N+1; i++)
        res[i] = 0;
    
    int carry=0;

    for(int i=N; i>=1; i--)
    {
        temp = i*A + carry;
        res[i] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        printf("%d", carry);

    for(int i=1; i<N+1; i++)
            printf("%d", res[i]);

    return 0;
    
}
