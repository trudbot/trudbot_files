//Created by 宋遗平 on 2022/5/29
//给出堆排序更一般性的实现
# include "../SORT/SortBase.c"
# define LeftChild(i) (2*i + 1)//以0开始的堆， i的左孩子为2*i + 1
# define Parent(i) ((i-1)/2)
# define ArrayLen 1000000
/**
 * 为了提高速度并减小内存消耗， 这里没有使用实际的ADT， 直接将要排序的数组当成一个无序堆， 要做的就是将这个堆有序化, 然后得到全部元素出队的结果
 * 在每次出队后， 数组的最后一个位置都空了出来， 为了避免使用第二个数组， 我们可以将出队的元素放在最后的单元中
 * 若要得到常见的递增序列， 每次出队的元素应该是最大的， 所以这里应该使用最大堆
*/

//算法步骤
//1, 对堆进行调整
/**如何对堆进行调整呢？
 * 从最后一个父结点开始， 对这个结点进行下滤
 * 逐步对前面的结点进行下滤
 这样的话， 其实每次就是将一个元素作为根， 且它的两个子堆都是满足堆序性的
 而这个根破坏是整个堆的堆序性的唯一元素， 将其下滤， 堆就恢复了堆序性
*/

//2, 得到有序序列
/**
 * 将索引0处的元素(最大元素)与堆尾元素进行交换， 堆大小减一
 * 此时又是子堆有堆序性， 将根下滤以调整堆
 * 重复直到堆为空
*/

void Swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Down(int *arr, int i, int end){//将i索引处的元素下滤
    /**
     * i为要下滤的元素索引
     * end为堆的最后一个元素的索引
    */
    int child;
    int Val = arr[i];
    while(LeftChild(i) <= end){
        child = LeftChild(i);
        if(child != end && arr[child+1] > arr[child]){
            child++;
        }
        //为了速度， 这里没有使用交换， 而是使用的向前插入
        if(Val > arr[child]){
            break;
        }else{
            arr[i] = arr[child];
            i = child;
        }
    }
    arr[i] = Val;
}

void HeapSort(int *arr, int len){//数据量一百万， 大概的平均值为250ms
    int i;

    //堆序化
    for(i = Parent(len-1); i>=0; i--){//由最后一个父节点向前遍历， 执行下滤
        Down(arr, i, len-1);
    }

    //将堆尾元素放到根上， 堆长度减一， 在对根进行下滤
    for(i=len-1; i>0; i--){
        Swap(arr, 0, i);
        Down(arr, 0, i-1);
    }
}

int main(void){
    int *arr;
    Generate_random_array(&arr, ArrayLen);
    long long start = GetTickCount();
    HeapSort(arr, ArrayLen);
    long long end = GetTickCount();
    printf("sort time: %lld ms\n", end - start);
    IsSorted(arr, ArrayLen);
}
