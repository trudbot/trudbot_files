"""有一个想写的函数
任意输入一个正整数x，输出range(1,x+1)的所有的连续子数组(长度至少为1）
如：
In：1
Out：[[1]]
In:3
Out:[[1], [2], [3], [1,2], [2,3], [1,2,3]]"""
import random


def temp_f(numbers):
    result = []
    array = list(range(1, numbers+1))
    for a in array:
        for i in range(numbers-a+1):
            result.append(array[i:i+a])
    return result
# 完美完成！！！


print(temp_f(4))

'''利用此函数可以解决其他问题'''
'''给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [0]
输出：0'''
print('-------------------')
nums = [random.randint(-10, 10) for i in range(5)]
print('nums', nums)


def max_sub_array(lit):
    result = []
    for i in temp_f(len(lit)):
        sum_ = 0
        for index in i:
            sum_ += lit[index-1]
        result.append(sum_)
    return max(result)


print(max_sub_array(nums))
