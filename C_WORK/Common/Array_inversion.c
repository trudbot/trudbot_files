# include <stdio.h>

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
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 8};
    int length = sizeof(arr)/sizeof(arr[0]);
    int i;
    
    for (i=0; i<length/2; i++)
    {
        exchange(&arr[i], &arr[length-i-1]);
    }

    traversal_print(arr, length);

    return 0;
    
}
