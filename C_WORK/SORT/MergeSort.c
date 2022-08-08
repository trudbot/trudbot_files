//测试一百万数据， 平均耗时约为156ms
//时间复杂度恒为O(log n), 空间复杂度为O(n)

# include "../SORT/SortBase.c"
#define LEN 1000000

void MergeSort_Recursion(int *arr, int len);

void MergeSort_Recursion_sub(int *arr, int left, int right, int* tempArr);

void merge(int *arr, int left, int mid, int right, int *tempArr);

void MergeSort_loop(int *arr, int len);


int main(void){
    int *arr;
    Generate_random_array(&arr, LEN);
    printf("\n");
    
    long long start = GetTickCount();
    MergeSort_loop(arr, LEN);
    long long end = GetTickCount();
    printf("loop time: %lld ms\n", end - start);
    // free(arr);
    // Generate_random_array(&arr, LEN);
    // start = GetTickCount();
    // MergeSort_Recursion(arr, LEN);
    // end = GetTickCount();
    // printf("Recursion time: %lld ms\n", end - start);

    free(arr);
}

void MergeSort_Recursion(int *arr, int len){
    int *temp = (int *)malloc(len*sizeof(int));
    MergeSort_Recursion_sub(arr, 0, len-1, temp);
    free(temp);
}

void MergeSort_Recursion_sub(int *arr, int left, int right, int* tempArr){//自顶向下
    if(left >= right)
        return;
    int mid = (left+right)/2;
    MergeSort_Recursion_sub(arr, left, mid, tempArr);
    MergeSort_Recursion_sub(arr, mid+1, right, tempArr);
    merge(arr, left, mid, right, tempArr);
}

void merge(int *arr, int left, int mid, int right, int *tempArr){
    int index=0;
    int i=left, j=mid+1;
    while(i<=mid && j<=right)
    {
        if(arr[i]>arr[j]){
            tempArr[index] = arr[j];
            j++;
        }
        else{
            tempArr[index] = arr[i];
            i++;
        }
        index++;
    }
    while(i <= mid){
        tempArr[index] = arr[i];
        i++;
        index++;
    }
    while (j <= right)
    {
        tempArr[index] = arr[j];
        j++;
        index++;
    }
    for(i=left; i<=right; i++)
    {
        arr[i] = tempArr[i-left];
    }
}

void MergeSort_loop(int *arr, int len){//自底向上
    int subLen;
    int *temp = (int *)malloc(sizeof(int)*len);
    int left, mid, right;
    for(subLen = 1; subLen < len; subLen <<= 1){
        left = 0;
        while(left < len){
            mid = left+subLen-1;
            if(mid >= len){
                mid = len-1;
            }
            right = mid+subLen;
            if(right >= len){
                right = len-1;
            }
            merge(arr, left, mid, right, temp);
            left = right+1;
        }
    }
    free(temp);
}