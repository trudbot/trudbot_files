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

void sort_1(int * array, int length)
{
    int i, count, j=0;
    do{
        count = 0;
        for (i=0; i<length-1-j; i++)
        {
            if (array[i]>array[i+1])
            {
                exchange(array+i, array+i+1);
                count++;
            }
        }
        j++;
    }while (count != 0);
}

void sort_2(int *array, int len)
{
    int i, j;
    for (j=len-1; j>0; j--)
    {
        for (i=0; i<j; i++)
            if (array[i]>array[i+1])
                exchange(&array[i], &array[i+1]);
    }
}

void bubbleSort(int *arr,int n)
{
	int m,i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(arr[j]>arr[j+1])
			{
				m=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=m;
			}
}

int main(void)
{
    int *arr;
    int n = 1000000;
    // printf("请指定数组长度:");
    // scanf("%d", &n);
    // printf("\n");

    Generate_random_array(&arr, n);
    time_t t1, t2;
    // time(&t1);
    // sort_1(arr, n);
    // time(&t2);
    // printf("sort_1排序时间:%ld秒", t2-t1);//sort_1排序时间:30秒|sort_1排序时间:31秒

    // time(&t1);
    // sort_2(arr, n);
    // time(&t2);
    // printf("sort_2排序时间:%ld秒", t2-t1);//sort_2排序时间:31秒|sort_2排序时间:31秒

    time(&t1);
    bubbleSort(arr, n);
    time(&t2);
    printf("别人写的排序时间:%ld秒", t2-t1);//别人写的排序时间:26秒|别人写的排序时间:25秒

    free(arr);

    return 0;
    
}