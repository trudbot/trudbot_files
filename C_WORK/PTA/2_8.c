/*
找出”内奸“数
在一个长度大于2的整数数组中存在一个内奸数，除内奸数外该数组其它元素的值均相等，要求输出内奸数的下标和值
如数组为{1, 0, 1, 1, 1}
输出为：索引为1， 值为0
*/

# include <stdio.h>

int find_mole_1(int *nums, int nums_size, int *return_index)
{
    int temp, i;
    for(i=0; i<nums_size; i++)
        if(nums[i] == nums[i+1])
        {
            temp = nums[i];
            break;
        }

    if(nums_size == i)
    {
        *return_index = 1;
        return nums[1];
    }

    for(i=0; i<nums_size; i++)
        if(nums[i] != temp)
        {
            *return_index = i;
            return nums[i];
        }
}

int find_mole_2(int *nums, int nums_size)
{
    int sum=0;
    for(int i=0; i<nums_size; i++)
        sum += nums[i];
    if(nums[0] == nums[1])
        return sum-nums[0]*(nums_size-1);
    else if(nums[0] == sum-nums[1]*(nums_size-1))
        return nums[0];
    else return nums[1];
}

int find_mole_3(int *nums, int nums_size, int *return_index)//best
{
    for(int i=1; i<nums_size-1; i++)
        if(nums[i] != nums[i+1])
        {
            if(nums[i] == nums[0])
            {
                *return_index = i+1;
                return nums[i+1];
            }
            else
            {
                *return_index = i+1;
                return nums[i];
            }
        }

    *return_index = 0;
    return nums[0];
}

int main(void)
{
    int arr[] = {100, 6, 6, 6, 6, 6};
    int mole, index;

    int len = sizeof(arr)/sizeof(int);

    mole = find_mole_3(arr, len, &index);
    

    printf("value is %d, index is %d", mole, index);

    return 0;
}
