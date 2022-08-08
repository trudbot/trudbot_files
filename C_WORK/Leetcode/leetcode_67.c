/*
67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
*/

//解决思路：模拟加法
char * addBinary(char * a, char * b){
    int len_a = strlen(a), len_b = strlen(b), reslen;
    if(len_a == 0)
        return b;
    if(len_b == 0)
        return a;
    if(len_b > len_a) reslen = len_b;
    else reslen = len_a;
    int j, bit = 0;
    char res[reslen];
    for(int i=1; i<=reslen; i++)
    {
        j = reslen-i;
        res[j] = '0';
        if(i <= len_a)
            res[j] += a[len_a-i]-'0';
        if(i <= len_b)
            res[j] += b[len_b-i]-'0';
        res[j] += bit;
        if(res[j]>='2'){
            res[j] -= 2;
            bit = 1;
        }else bit = 0;       
    }
    if(bit){
        char *s = (char*)malloc(reslen+2);
        s[0] = '1';
        for(j = 1; j<=reslen; j++)
            s[j] = res[j-1];
        s[reslen+1] = '\0';
        return s;
    }else{
        char *s = (char*)malloc(reslen+1);
        for(j=0; j<reslen; j++)
            s[j] = res[j];
        s[reslen] = '\0';
        return s;
    }
    return;
}