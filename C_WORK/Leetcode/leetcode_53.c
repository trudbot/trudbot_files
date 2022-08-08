/*
53. 最大子序和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define N 10

//方法一：暴力法
int maxSubArray_1(int* nums, int numsSize)
{
    int sum, res=0;
    for(int i=0; i<numsSize; i++)
    {
        sum=0;
        for(int j=i; j<numsSize; j++)
        {
            sum += nums[j];
            if(sum>res)
                res = sum;
        }
    }
    return res;
}
//方法二：贪心法
// 核心是， 最大和的子序任取前n个元素， 其和必然要大于0(不考虑最大和为负数的情况下)
int maxSubArray_2(int* nums, int numsSize){
    int ThisSum=0, MaxSum=0;
    for(int i=0; i<numsSize; i++)
    {
        ThisSum+=nums[i];
        if(ThisSum<=0)
            ThisSum=0;
        if(ThisSum>MaxSum)
            MaxSum = ThisSum;
    }
    return MaxSum;
}

int max(int i, int j)
{
    if(i > j)
        return i;
    return j;
}

int maxSubArray_3(int* nums, int numsSize)//另一种形式
{
    int sum, res;
    sum = 0, res = nums[0];
    for(int i=0; i<numsSize; i++)
    {
        sum = max(nums[i], sum+nums[i]);
        res = max(sum, res);
    }
    return res;
}

void ShowAArray(int *arr, int n)
{
    printf("array: ");
    for(int i=0; i<n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

void Creat_random_array(int **q, int len)
{
    *q = (int *)calloc(len, sizeof(int));

    srand((unsigned int)time(NULL));
    
    for (int i=0; i<len; i++)
    {
        (*q)[i] = rand()%10 - 5;
    }
}


int main(void)
{
    int *arr;

    Creat_random_array(&arr, N); 

    ShowAArray(arr, N);

    printf("%d", maxSubArray_3(arr, N));

    return 0;
}


