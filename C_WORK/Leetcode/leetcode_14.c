/*
14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 

提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
# include <stdio.h>
# include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *res = (char*)malloc(200*sizeof(char));
    char temp1, temp2;
    int j, count = 0;
    for (int i=0; i<200; i++)
    {
        temp1 = strs[0][i];
        for (j=1; j<strsSize; j++)
        {
            temp2 = strs[j][i];
            if (temp1 != temp2)
                break;
        }
        if (j == strsSize)
            {
                res[count] = temp1;
                count++;
            }
    }

    return res;
}

int main(void)
{
    int strsize = 3;
    char ** strs = (char **)calloc(strsize, sizeof(char*));
    char str1[] = "abcff";
    char str2[] = "abcfjjf";
    char str3[] = "abcfei";
    strs[0] = str1;
    strs[1] = str2;
    strs[2] = str3;

    char *res = longestCommonPrefix(strs, strsize);
    printf("%s", res);

    free(res);
    free(strs);
    return 0;
}