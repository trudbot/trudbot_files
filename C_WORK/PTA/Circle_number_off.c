/* 
围圈报数问题
题目描述：
有n（n<=100）围成一圈，顺序排号（从1排到n）。 从第一个人开始报数（从1报到m（m<=9))，凡报到m的人退出圈子， 问最后留下的是原来第几号的那位？
*/
# include <stdio.h>

int main(void)
{
    int n, m, i, j ,count;
    
    scanf("%d %d", &n, &m);
    int arr[n];

    for(i=0; i<n; i++)
        arr[i] = i+1;
    
    i = 1;
    j = 0;
    count = 0;

    while(count != n-1)
    {
        if (arr[j] != 0)
        {
            if(i == m)
            {
                count++;
                arr[j] = 0;
            }
            i++;
        }
        j++;

        if (i > m)
            i = 1;
        if(j > n-1)
            j = 0;
    }

    for(j=0; j<n; j++)
        if(arr[j] != 0)
        {
            printf("The answer is %d", arr[j]);
            break;
        }

    return 0;
}
