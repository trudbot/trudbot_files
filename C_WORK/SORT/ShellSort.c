//希尔排序是对插入排序的改进
//在数据相对有序的情况下， 插入排序的效率是较高的。
//希尔排序以增量i将数组划分为i部分， 每部分相邻两个元素索引相差i
//每趟对划分出的各部分分别进行直接插入排序
//而增量是逐渐减小的， 最终减小到1， 对整个数组进行插入排序， 所以希尔排序又被叫做缩小增量排序
//增量在每趟取的值hn....h3, h2, h1的集合叫做增量序列， 增量序列唯一的要求是递减且h1为1

#include "SortBase.c"

//使用Shell序列
void ShellSort_1(int* arr, int len){//一百万数据量, 数据范围0~1万， 平均为290ms
    int i, j, increment;
    int temp;

    for(increment = len/2; increment > 0; increment /= 2){
        for(i = increment; i<len; i++){
            temp = arr[i];
            for(j = i-increment; j>=0; j-=increment){
                if(arr[j] > temp){
                    arr[j + increment] = arr[j];
                }else{
                    break;
                }
            }
            arr[j + increment] = temp;
        }
    }
}


//Sedgewick序列, 具体计算公式不表
int Sedgewick[]={28,
    1,5,19,41,109,209,505,929,
    2161,3905,8929,16001,36289,64769,146305,260609,
    587521,1045505,2354689,4188161,9427969,16764929,37730305,67084289,
    150958081,268386305,603906049,1073643521};

//使用Sedgewick序列的希尔排序
void ShellSort_2(int *arr, int len){//一百万数据量, 数据范围0~1万， 219ms
    int i, j;
    int currIndex = 1, increment;
    int temp;
    while(Sedgewick[currIndex+1] < len){
        currIndex++;
    }

    for(    increment = Sedgewick[currIndex];
            currIndex>=1;
            increment=Sedgewick[--currIndex])
    {
        for(i = increment; i<len; i++){
            temp = arr[i];
            for(j = i-increment; j>=0; j-=increment){
                if(arr[j] > temp){
                    arr[j + increment] = arr[j];
                }else{
                    break;
                }
            }
            arr[j + increment] = temp;
        }
    }
}

int main(void){
    int *arr;
    int LEN = 1000000;
    Generate_random_array(&arr, LEN);
    printf("\n");
    long long start = GetTickCount();
    ShellSort_2(arr, LEN);
    long long end = GetTickCount();
    printf("loop time: %lld ms\n", end - start);
    IsSorted(arr, LEN);
}
