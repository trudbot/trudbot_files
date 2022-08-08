/*
排它平方数
题目描述
小明正看着 203879 这个数字发呆。
原来，203879 * 203879 = 41566646641
这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。
具有这样特点的6位数还有一个，请你找出它！
再归纳一下筛选要求：
1. 6位正整数
2. 每个数位上的数字不同
3. 其平方数的每个数位不含原数字的任何组成数位
答案是一个6位的正整数。

*/

# include <stdio.h>

int ElemInArr(int elem, int *arr){
    for(int i=0; i<6; i++)
        if(elem == arr[i])
            return 1;
    return 0;
}

int Func(int *arr)
{
    int temp;
    int carry=0;
    for(int i=5; i>=0; i--)
    {
        temp = arr[i]*arr[i] + carry;
        carry = temp / 10;
        temp %= 10;
        if(ElemInArr(temp, arr))
            return 0;
    }
    if(ElemInArr(carry, arr))
        return 0;
    return 1;
}

void getunits(int *arr, int num)
{
    int index = 5;
    while(num != 0)
    {
        arr[index] = num % 10;
        num /= 10;
        index--;
    }
}

int main(void){
    int i=133334;
    int arr[6];
    getunits(arr, i);
    for(int i=0; i<6; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("%d", Func(arr));

    // int i = 100000;
    // int units[6];
    // int carry = 0;
    // int temp;
    // while(1){
    //     getunits(units, i);

    //     if(Func(units))
    //         break;
    //     i++;
    // }
    // printf("result is %d", i);
}