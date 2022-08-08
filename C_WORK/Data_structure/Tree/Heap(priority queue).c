/*
堆是一种数据结构， 通常指具有堆序性的完全二叉树， 一般用数组实现

堆序性： 任意子树都可以视为一个堆， 任意节点的值与其孩子之间有固定的大小关系
如一个堆中每个结点的值都大于它的两个孩子， 则称此堆为最大堆， 类似的有最小堆

优先队列是一种特殊的队列， 它的每个元素都被赋予了一个优先级， 出队的规则并不是先进先出， 而是优先级最低(或最高)的先出
优先级的ADT包括{
    Insert, 等价于入队EnQueue
    DeleteMin, 让优先级最低的元素DeQueue
    (DeleteMax)
}

本程序以最小优先队列举例
*/
#include <stdio.h>
#include <stdlib.h>
#define MinVal -1*__INT_MAX__
#define MaxVal __INT_MAX__

struct Heap;
enum bool;
typedef struct Heap *PriorityQueue;
typedef int ElementType;
typedef enum bool bool;
typedef unsigned int Index;

//heap struct
struct Heap{
    int Capacity;//堆的最大容量
    int size;//堆中实际元素个数
    ElementType* vals;//存放数据
};//ElemType为int， 也就是只存储了优先级， 实际上这里可以是任意复杂的结构体类型

enum bool {
    false = 0, true
};

//初始化堆
PriorityQueue InitHeap(int MaxElems){
    PriorityQueue P;

    P = (PriorityQueue)malloc(sizeof(struct Heap));
    if(!P){
        return NULL;
    }

    P->vals = (ElementType*)malloc(sizeof(ElementType)*(MaxElems+1));//多请求一个位置， 0索引处不放元素
    if(!P->vals){
        free(P);
        return NULL;
    }

    P->Capacity = MaxElems;
    P->size = 0;
    P->vals[0] = MinVal;//0索引处为一个非常小的值， 便于插入时的比较

    return P;
}

//队列是否已满
bool IsFull(PriorityQueue P){
    return P->size == P->Capacity;
}

//队列是否为空
bool IsEmpty(PriorityQueue P){
    return P->size == 0;
}

bool IndexIsValid(PriorityQueue P, Index i){
    return i>=1 && i<=P->size;
}

//获取根结点值
ElementType getRootVal(PriorityQueue P){
    return P->vals[1];
}

// i less than j, in P
bool IsLess(PriorityQueue P, Index i, Index j){
    return P->vals[i] < P->vals[j];
}

//交换操作
void Swap(PriorityQueue P, Index i, Index j){
    int t = P->vals[i];
    P->vals[i] = P->vals[j];
    P->vals[j] = t;
}

//上滤(percolate up)——自下而上堆有序化
Index UP(PriorityQueue P, Index i){
    /*
    P:队列
    i:要上滤的元素位置
    */
   /*因为堆中数据是从1开始的， 所以对于一个索引为i的元素
    它的左孩子为2i， 右孩子为2i+1
    它的父结点为i/2
    */
    while(i > 1 && IsLess(P, i, i/2)){
        Swap(P, i, i/2);//当然上滤和下滤的操作不一定要用交换
        i /= 2;
    }
    return i;
}

//下滤(percolate down)——自上而下堆有序化
Index DOWN(PriorityQueue P, Index i){
    //参数列表与上滤类似
    int child;
    while(i*2 <= P->size){
        child = i*2;
        //维护child为两个孩子中优先级更小的那个
        if(child != P->size && IsLess(P, child+1, child)){
            child++;
        }

        //若i的优先级比child小， 则i已达到正确的位置， 下滤结束
        if(IsLess(P, i, child)){
            break;
        }
        Swap(P, i, child);
        i = child;
    }
    return i;
}

//入队
bool Insert(ElementType x, PriorityQueue P){
    if(IsFull(P)){
        return false;
    }
    P->vals[++P->size] = x;
    UP(P, P->size);
    return true;
}//O(logN)

//Min出队
ElementType DeleteMin(PriorityQueue P){
    if(IsEmpty(P)){
        return MinVal;
    }
    int Min = getRootVal(P);
    P->vals[1] = P->vals[P->size--];
    DOWN(P, 1);
    return Min;
}//O(logN)

PriorityQueue FreeHeap(PriorityQueue P){
    free(P->vals);
    free(P);
    return NULL;
}

//假设通过其它手段， 我们获取了某个结点元素的位置
//则有几种操作将在一定程度上可行

//降低i位置元素的优先级
bool DecreaseKey(PriorityQueue P, int delta, Index i){
    if(!IndexIsValid(P, i)){
        return false;
    }
    P->vals[i] -= delta;
    UP(P, i);
    return true;
}

//增加i位置元素的优先级
bool IncreaseKey(PriorityQueue P, int delta, Index i){
    if(!IndexIsValid(P, i)){
        return false;
    }
    P->vals[i] += delta;
    DOWN(P, i);
    return true;
}

//删除某个位置的元素
ElementType Delete(PriorityQueue P, Index i){
    if(DecreaseKey(P, MaxVal, i) == false){
        return MinVal;
    }
    return DeleteMin(P);
}

/*
堆排序
优先队列中每次出队的都是优先级最大或最小的元素， 显然这个性质可以用来设计排序

若将一个数组共N个元素放入堆中， 每次Insert花费平均情况O(1)~最坏情况O(logN)
所以插入的平均时间是O(N) 

但每次出队都几乎要下滤到最底层， 所以出队的平均时间是O(NlogN)

所以堆排序的时间复杂度是O(N*logN), 是目前为止理论上时间复杂度最优的排序， 但在实践中却发现慢于希尔排序
*/

//堆排序
void HeapSort(int* arr, int len){
    PriorityQueue P = InitHeap(len);
    for(int i=0; i<len; i++){
        Insert(arr[i], P);
    }
    for(int i=0; i<len; i++){
        arr[i] = DeleteMin(P);
    }
    FreeHeap(P);
}//这里使用了封装好的堆ADT来实现堆排序， 虽然方便， 但无疑会大大降低程序运行速度, 以及多用了不必要的内存空间

int main(void){
    int arr[] = {3, 9, 6, 10, 4};
    HeapSort(arr, 5);
    for(int i=0 ; i<5; i++){
        printf("%d ", arr[i]);
    }
}