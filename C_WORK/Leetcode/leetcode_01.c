/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//  Note: The returned array must be malloced, assume caller calls free().
# include <stdio.h>
# include <stdlib.h>

void twoSum_1(int* nums, int numsSize, int target, int* returnSize);
void twoSum_2(int* nums, int numsSize, int target, int* returnSize);// 待办

int main(void)
{
    int nums[] = {3, 2, 4};
    int* res_index = (int*)malloc(2*sizeof(int));
    int len = sizeof(nums)/sizeof(int);
    int target = 6;
    twoSum_1(nums, len, target, res_index);
    for (int i=0; i<2; i++)
    {
        printf("%d\n", res_index[i]);
    }

}

void twoSum_1(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    
    for(i=0; i<numsSize-1; i++)
        for (j=i+1; j<numsSize; j++)
            if (nums[i]+nums[j] == target)
                {
                    returnSize[0] = i;
                    returnSize[1] = j;
                    return;
                }
}
