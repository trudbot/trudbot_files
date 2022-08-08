//快速排序
//最好情况下时间复杂度为O(nlog n), 最坏情况下为O(n^2)
/*
基本思想是随机取一基准数， 将数组中比基准数小和大的数分别放在基准数左右两边（分割）
再对基准数左右两边的子数组进行同样的分割操作， 以此往复。
当子数组的长度不大于3时， 经过分割操作后就是有序的。
最终总数组呈现有序状态。
*/
#include "../SORT/SortBase.c"
#include "../SORT/Straight_Insertion_Sort.c"
#define LEN 1000000


void QuickSort1(int *arr, int start, int end);
void QuickSort2(int *arr, int start, int end);

int main(void){
    int *arr;
    time_t t1, t2;
    Generate_random_array(&arr, LEN);
    // traversal_print(arr, LEN);
    long long start = GetTickCount();
    QuickSort2(arr, 0, LEN-1);
    long long end = GetTickCount();
    printf("time: %lld ms\n", end - start);
    // traversal_print(arr, LEN);
    IsSorted(arr, LEN);

    free(arr);
}

void QuickSort1(int *arr, int left, int right){//百万数据量, 数据范围0~1万, 109ms
    if(left >= right){
        return;
    }
    int pivot = arr[left];
    int i = left, j = right;
    while(i < j){
        while(i < j && arr[j] > pivot){
            j--;
        }
        if(i == j){
            break;
        }
        arr[i++] = arr[j];
        while(i < j && arr[i] < pivot){
            i++;
        }
        if(i == j){
            break;
        }
        arr[j--] = arr[i];
    }
    arr[i] = pivot;
    QuickSort1(arr, left, i-1);
    QuickSort1(arr, i+1, right);
}


int Median(int* arr, int left, int right){
    int center = (left+right)/2;

    //对三个元素进行插入排序
    int temp = arr[center];
    if(arr[left] > temp){
        arr[center] = arr[left];
        arr[left] = temp;
    }
    temp = arr[right];
    if(arr[center] > temp){
        arr[right] = arr[center];
        if(arr[left] > temp){
            arr[center] = arr[left];
            arr[left] = temp;
        }else{
            arr[center] = temp;
        }
    }

    //交换left+1 与 center， 方便后续进行分割
    temp = arr[center];
    arr[center] = arr[left+1];
    arr[left+1] = temp;


    return arr[left+1];
}

//快排优化——三数中值分割
void QuickSort2(int *arr, int left, int right){//百万数据量, 数据范围0~1万, 110ms
    if(right-left+1 < 4){//当数组长度小于4时， 直接进行插入排序
        InsertionSort(arr+left, right-left+1);
        return;
    }
    int temp;
    int pivot = Median(arr, left, right);//将枢纽选为左、中、右元素中中间那个
    int i = left+1, j = right-1;//左右自然不用在分割， left+1为枢纽所在位置

    while(i < j){
        while(i < j && arr[j] > pivot){
            j--;
        }
        if(i == j){
            break;
        }
        arr[i++] = arr[j];
        while(i < j && arr[i] < pivot){
            i++;
        }
        if(i == j){
            break;
        }
        arr[j--] = arr[i];
    }
    arr[i] = pivot;
    QuickSort1(arr, left, i-1);
    QuickSort1(arr, i+1, right);
}//可以发现优化版本面对随机数据时并不比普通版本有什么优势， 但这种方法能有效消除预排序数组的坏情形


/*
# 快排的时间复杂度分析

在分割操作中， 数组的每个元素都要被遍历一次， 因此快排中每一层递归的时间复杂度为O(n)， n为当前子数组的长度
由于快排的基准数是随机选取的（第一个元素）， 因此快排的时间复杂度也带有随机性。
如果每一次选取的基准数都恰好是当前子数组的中位数， 则每次都把问题规模为n的问题分解为两个n/2的子问题， 递归次数为log2 n, 时间复杂度为O(nlogn)
如果每一次选取的基准数都恰好是当前子数组的最大数/最小数， 则每次都把问题规模n的问题分解为n-1和1的问题， 递归次数为n, 时间复杂度为O(n^2)

因此, 时间复杂度在
最好情况下： O(nlogn)
最坏情况下： O(n^2)
平均情况下： O(nlogn)  # 数学角度分析
*/