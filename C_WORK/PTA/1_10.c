/*
1-10 逆序输出整数
输入任意一个正整数，要求逆序输出这个整数
如输入123， 输出321
注意当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。
*/

# include <stdio.h>

int main(void)
{
    int i, res = 0;
    printf("please enter a integer: ");
    scanf("%d", &i);

    while (i != 0)
    {
        res = res*10 + i%10;
        i /= 10;
    }

    printf("result = %d", res);
    return 0;
}

