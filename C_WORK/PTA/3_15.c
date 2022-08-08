/*
7-15 判断一个数是否为素数
所谓素数，是指除了1和其本身外，不能被其它任何整数整除的正整数，2是最小的素数。
现在，用户输入一个整数，判断它是否为素数。
*/
# include <stdio.h>
# include <math.h>

int Is_prime(int i);

// int main(void)
// {
//     int i;
    
//     printf("please enter a integer:");
//     scanf("%d", &i);

//     if (Is_prime(i))
//         printf("%d is a prime.", i);
//     else
//         printf("%d is not a prime.", i);

//     return 0;
// }

int Is_prime(int i)
{
    int j;

    if (i == 2 || i==3)
        return 1;
    if (i%6 != 1 && i%6 != 5)
        return 0;
    
    for (j = 5; j<= (int)sqrt(i); j++)
        if (i%j == 0 || i%(j+2) == 0)
            return 0;
    return 1;
    
}

int main(void){
    printf("%d", 100);
    goto label;
    printf("9293");

    label:printf("32jf");
}

