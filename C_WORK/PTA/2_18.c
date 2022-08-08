/*
2.18 , 水仙花数
水仙花数定义： 一个三位数的个位、十位和百位的立方和等于其本身
请你输出所有水仙花数。
*/

# include <stdio.h>
# include <math.h>

int main(void)
{
    int i, j, k; //用以存储个位十位和百位
    
    for (int temp=100; temp<1000; temp++)
    {
        i = temp%10;
        j = temp%100/10;
        k = temp/100;

        if (pow(i, 3)+pow(j, 3)+pow(k, 3) == temp)
            printf("%d是水仙花数\n", temp);
    }

    return 0;
}