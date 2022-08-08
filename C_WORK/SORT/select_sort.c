# include <stdio.h>
# include <stdlib.h>
# include <time.h>


void traversal_print(int * j, int length)
{
    int i;
    for (i = 0; i<length; i++)
    {
        printf("%d\t", j[i]);
    }
    printf("\n");
}

void Generate_random_array(int **q, int len)
{
    *q = (int *)calloc(len, sizeof(int));

    srand((unsigned int)time(NULL));
    
    for (int i=0; i<len; i++)
    {
        (*q)[i] = rand()%100;
    }
}

int min(int *arr, int start, int len)
{
    int res = start;
    for (int j=start+1; j<len; j++)
    {
        if (arr[j]<arr[res])
            res = j;
    }
    return res;
}

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void sort(int *arr, int len)
{
    int i;
    for (i=0; i<len-1; i++)
        swap(&arr[i], &arr[min(arr, i, len)]);
}

int main(void)
{
    int *arr;
    int n = 10;
    time_t t1, t2;
    // printf("请指定数组长度:");
    // scanf("%d", &n);
    // printf("\n");

    Generate_random_array(&arr, n);


    time(&t1);
    sort(arr, n);
    time(&t2);
    printf("排序时间:%ld秒", t2-t1);//排序时间:10秒|排序时间:10秒|排序时间:10秒

    free(arr);

    return 0;
    
}