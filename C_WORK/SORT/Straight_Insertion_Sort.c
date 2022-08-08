#include "SortBase.c"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void InsertionSort(int * arr, int length)
{
    int i, temp, j;
    for (i=1; i<length; i++)
    {
        temp = arr[i];
        for (j=i-1; j>=0; j--)
        {
            if (arr[j]>temp)
                arr[j+1] = arr[j];
            else
                break;         
        }
        arr[j+1] = temp;
    }
}

// int main(void)
// {
//     int *arr;
//     int n = 100000;
//     time_t t1, t2;
//     // printf("请指定数组长度:");
//     // scanf("%d", &n);
//     // printf("\n");

//     Generate_random_array(&arr, n);


//     time(&t1);
//     sort(arr, n);
//     time(&t2);
//     printf("排序时间:%ld秒", t2-t1);//排序时间:5秒|排序时间:5秒|排序时间:6秒

//     free(arr);

//     return 0;
    
// }