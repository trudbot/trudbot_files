/*
7-7 汉诺（Hanoi）塔问题 (5 分)
古代某寺庙中有一个梵塔，塔内有3个座A、B和C，座A上放着64个大小不等的盘，其中大盘在下，小盘在上。有一个和尚想把这64 个盘从座A搬到座B，但一次只能搬一个盘，搬动的盘只允许放在其他两个座上，且大盘不能压在小盘上。现要求用程序模拟该过程，输入一个正整数n，代表盘子的个数，编写函数

void hanoi(int n,char a,char b,char c)
其中，n为盘子个数，从a座到b座，c座作为中间过渡，该函数的功能是输出搬盘子的路径。

输入格式:
输入在一行中给出1个正整数n。

输出格式:
输出搬动盘子路径。

输入样例:
3
输出样例:
a-->b
a-->c
b-->c
a-->b
c-->a
c-->b
a-->b
*/

# include <stdio.h>

void hanoi(int n, char now, char target, char other)
{
    if(n == 1)
    {
        printf("%c-->%c\n", now, target);
        return;
    }
    else{
        hanoi(n-1, now, other, target);
        hanoi(1, now, target, other);
        hanoi(n-1, other, target, now);
    }
}

int HanoiRMN(int n)
{
    if(n == 1)
        return 1;
    return 2*f(n-1)+1;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    printf("number of moves is %d", HanoiRMN(n));
    return 0;
}

