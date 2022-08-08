/*
大数乘法——模拟手算
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void Reversal(char *str)//将字符串逆序
{
    char *low = str;
    char *high = str+strlen(str)-1;
    char temp;
    while(low < high)
    {
        temp = *low;
        *low = *high;
        *high = temp;
        low++;
        high--;
    }
}

char* MultiplyString(char *num1, char *num2){
    int len1 = strlen(num1), len2 = strlen(num2);
    int arr1[len1], arr2[len2];
    int ans[len1+len2];
    int carry = 0;
    Reversal(num1);
    Reversal(num2);
    
    //将两个整数字符串转换成数组整数数组形式， 并对answer array 作初始化
    for(int i=0; i<len1; i++)
        arr1[i] = num1[i] - '0';
    for(int i=0; i<len2; i++)
        arr2[i] = num2[i] - '0';
    for(int i=0; i<len1+len2; i++)
        ans[i] = 0;
    
    //以下是最核心的两个循环
    for(int i=0; i<len1; i++)
        for(int j=0; j<len2; j++)
            ans[i+j] += arr1[i] * arr2[j]; 
    
    for(int i=0; i<len1+len2; i++)
    {
        ans[i] += carry;
        carry = ans[i] / 10;
        ans[i] %= 10;
    }

    //将结果再转换回字符串形式
    int len = len1+len2;
    for(int i=len1+len2-1; i>=0; i--)
    {
        if(ans[i] == 0)
            len--;
        else break;
    }

    char *res = (char *)malloc(sizeof(char)*len);
    for(int i=0; i<len; i++)
        res[i] = ans[i] + '0';
    Reversal(res);
    return res;

}

int main(void)
{
    char num1[100], num2[100];
    printf("Please enter the first interger:");
    gets(num1);
    printf("Please enter the second interger:");
    gets(num2);//以字符串的形式接受两个整数

    char *res = MultiplyString(num1, num2);
    puts(res);

    // free(res);
    return 0;
}
