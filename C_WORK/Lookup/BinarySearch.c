# include <stdio.h>
# define NOTFOUND -1

int BinarySearch(int *arr, int len, int target)
{
    int start, end, mid;

    start = 0;
    end = len-1;

    while(start <= end)
    {
        int mid = start + ((end - start) >> 1); 
        if(target > arr[mid])
            start = mid+1;
        else if(target < arr[mid])
            end = mid-1;
        else
            return mid;
    }

    return NOTFOUND;
}

int main(void){
    int arr[10] = {-19, -2, 1, 3, 6};
    printf("%d", BinarySearch(arr, 5, -19));
}