/* 
9. 回文数
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
 

示例 1：
输入：x = 121
输出：true

示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3：
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

# include <stdio.h>

int isPalindrome(int x)
{
    long int res = 0;
    int temp = x;
    if (x < 0)
        return 0;
    while (x != 0)
    {
        res = 10*res + x%10;
        x /= 10;
    }
    if (temp == res)
        return 1;
    return 0;
}

int main(void)
{
    printf("%d", isPalindrome(-121));
}