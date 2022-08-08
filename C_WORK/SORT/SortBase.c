#ifndef SortBase
#define SortBase
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <windows.h>

typedef enum{
    false, true
}bool;

void swap(int *i, int *j)
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
        printf("%d ", j[i]);
    }
    printf("\n");
}

void Generate_random_array(int **q, int len)
{
    *q = (int *)calloc(len, sizeof(int));

    srand((unsigned int)time(NULL));
    
    for (int i=0; i<len; i++)
    {
        (*q)[i] = rand()%10000;
    }
}

void IsSorted(int *arr, int len){
    for(int i=0; i<len-1; i++){
        if(arr[i] > arr[i+1]){
            printf("Error\n");
            return;
        }
    }
    printf("Sorted");
}
#endif
