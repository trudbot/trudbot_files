/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([)]"
输出：false

示例 5：
输入：s = "{[]}"
输出：true

*/

//解决方法——栈匹配
/*
用一个数组模拟栈
每遇到左括号， 就加入栈中
对于一个有效括号字符串：
    每遇到一个右括号， 栈顶必然是相同类型的左括号， 于是令栈顶元素出栈；
    遍历完所有元素后， 栈中元素必然全部已出栈
*/

int isValid(char * s){
    int len=strlen(s);
    char str[len];
    int index=0;
    for(int i=0; i<len; i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
            str[index] = s[i];
            index ++;
        }
        else if(s[i]=='}' || s[i]==']')
        {
            if(index == 0)
                return 0;
            else if(str[index-1] != s[i]-2)
                return 0;
            else
                index--;
        }
        else if(s[i]==')')
        {
            if(index == 0)
                return 0;
            else if(str[index-1] != s[i]-1)
                return 0;
            else
                index--;
        }
    }
    if(index != 0)
        return 0;
    return 1;
}