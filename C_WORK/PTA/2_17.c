/*
2-16 求一元二次方程的根 (20 分)
本题目要求一元二次方程ax^2＋bx＋c＝0的根，结果保留2位小数。
输入在一行中给出3个浮点系数a、b、c，中间用空格分开。
根据系数情况，输出不同结果：

1)如果方程有两个不相等的实数根，则每行输出一个根，先大后小；

2)如果方程有两个不相等复数根，则每行按照格式“实部+虚部i”输出一个根，先输出虚部为正的，后输出虚部为负的；

3)如果方程只有一个根，则直接输出此根；

4)如果系数都为0，则输出"Zero Equation"；

5)如果a和b为0，c不为0，则输出"Not An Equation"。
*/

# include <stdio.h>
# include <math.h>

int main (void)
{
    float a, b, c;
    
    scanf("%f %f %f", &a, &b, &c);
    
    float delta = pow(b, 2)-4*a*c;
    
    if (a==0 && b==0 && c==0)
        printf("Zero Equation");
    
    else if (a==0 && b==0 && c!=0)
        printf("Not An Equation");
    
    else if(a == 0)
        printf("%.2f", -c/b);
    
    else if (delta == 0)
        printf("%.2f", -b/(2*a));
    
    else if(delta > 0)
    {
        printf("%.2f\n", (-b+sqrt(delta))/(2*a));
        printf("%.2f", (-b-sqrt(delta))/(2*a));
    }
    
    else if (delta < 0)
    {
        if (b != 0)
        {
            printf("%.2f+%.2fi\n", -b/(2*a), sqrt(-delta)/(2*a));
            printf("%.2f-%.2fi", -b/(2*a), sqrt(-delta)/(2*a));
        }
        else
        {
            printf("0.00+%.2fi\n", sqrt(c/a));
            printf("0.00-%.2fi", sqrt(c/a));
        }
    }
    
    return 0;
}
