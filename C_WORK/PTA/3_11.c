/*
7-11 统计数字字符和空格 (15 分)
本题要求编写程序，输入一行字符，统计其中数字字符、空格和其他字符的个数。
输入格式:
输入在一行中给出若干字符，最后一个回车表示输入结束，不算在内。
输出格式:
在一行内按照
blank = 空格个数, digit = 数字字符个数, other = 其他字符个数
的格式输出。
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
    char str[100];
    int blank = 0, digit = 0, other = 0;
    
    gets(str);
    
    for (int i=0; i<100; i++)
    {
        if (str[i] == '\0')
            break;
        else if(str[i] == ' ')
            blank++;
        else if ((int)str[i]>=48 && (int)str[i]<=57)
            digit++;
        else
            other++;
    }
    
    printf("blank = %d, digit = %d, other = %d", blank, digit, other);
    
    return 0;
}