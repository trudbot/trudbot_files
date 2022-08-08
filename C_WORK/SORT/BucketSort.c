# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void exchange(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

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

//每个元素一个桶
void bucketsort(int *arr, int len){
    int bucket[100] = {0};
    int index = 0;
    for(int i=0; i<len; i++)
        bucket[arr[i]]++;
    for(int i=0; i<100; i++)
    {
        if(bucket[i] == 0)
            continue;
        else
        {
            for(int j=0; j<bucket[i]; j++)
            {
                arr[index] = i;
                index++;
            }
        }
    }
}

void QKSORT(int *q, int start, int tail)
{
    if (start>tail)
        return;
    int i = start, j = tail, temp = q[start];
    while (i != j)
    {
        while (q[i]<=temp && i<j)
            i++;
        while(q[j]>=temp && i<j)
            --j;
        if (j>i)
        {
            exchange(&q[j], &q[i]);
        } 

    }
    exchange(&q[start], &q[i]);
    
    QKSORT(q, start, i-1);
    QKSORT(q, i+1, tail);

}
int main(void)
{
    int *arr;
    int n = 100000000;
    time_t t1, t2;
    // printf("请指定数组长度:");
    // scanf("%d", &n);
    // printf("\n");

    Generate_random_array(&arr, n);


    time(&t1);
    bucketsort(arr, n);
    time(&t2);
    printf("桶排序排序时间:%ld秒\n", t2-t1);//排序时间:10秒|排序时间:10秒|排序时间:10秒

    // time(&t1);
    // QKSORT(arr, 0, n-1);
    // time(&t2);
    // printf("快速排序排序时间:%ld秒\n", t2-t1);//排序时间:10秒|排序时间:10秒|排序时间:10秒
    // free(arr);

    return 0;
    
}