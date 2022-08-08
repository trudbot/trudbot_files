//第二次大作业——min heap实现完整Huffman编码
//Created by 宋遗平 on 2022/6/2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define LeftChild(i) (2*i + 1)//以0索引开始的堆， i的左孩子为2*i + 1
# define Parent(i) ((i-1)/2)

typedef unsigned Index;

//最小堆的结点， 存放字符以及其权值
typedef struct HuffmanNode{
    char key;
    unsigned weight;//字符的权值
    struct HuffmanNode *left, *right;
    // int num;//结点的编号，便于生成绘图代码 
}*HuffmanNode;

//最小堆的结构
typedef struct MinHeap{
    unsigned Capacity;//最大容量
    unsigned size;//实际元素个数
    HuffmanNode* array;
}*MinHeap;

//bool类型
typedef enum{
    false, true
}bool;

//使用静态的unsigned数组， 构造简单的ascii映射， 用于记录字符的频率
static unsigned Weights[128];//由于静态存储区的特性， 数组已经是全0数组了
static int charNum;//用于存放字符的种数(待定)


//new a Huffman Node
HuffmanNode NewNode(char key, unsigned weight){
    HuffmanNode node = (HuffmanNode)malloc(sizeof(struct HuffmanNode));
    node->key = key;
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

//堆是否只有一个元素
bool IsOnlyOne(MinHeap heap){
    return heap->size == 1;
}

//i结点权值是否小于j结点
bool IsLess(MinHeap heap, Index i, Index j){
    return heap->array[i]->weight < heap->array[j]->weight;
}

//new a min heap
MinHeap NewHeap(unsigned capacity){
    MinHeap heap = (MinHeap)malloc(sizeof(struct MinHeap));
    heap->Capacity = capacity;
    heap->size = 0;
    heap->array = (HuffmanNode *)calloc(capacity, sizeof(HuffmanNode));
    return heap;
}

//交换
void Swap(MinHeap heap, Index i, Index j){
    HuffmanNode node = heap->array[i];
    heap->array[i] = heap->array[j];
    heap->array[j] = node;
}

//上滤操作
void PercolateUp(MinHeap heap, Index i){
    Index iParent = Parent(i);
    while(i!=0 && IsLess(heap, i, iParent)){//如果i的父节点的权值小于i的权值， 则交换两个结点
        Swap(heap, i, iParent);
        i = iParent;
        iParent = Parent(i);
    }
}

//下滤操作
void PercolateDown(MinHeap heap, Index i){
    Index child = LeftChild(i);
    while(child < heap->size){
        if(child != heap->size-1 && IsLess(heap, child+1, child)){
            child++;//如果有右结点且右结点的权小于左结点， 则目标结点应该为右结点
        }
        if(IsLess(heap, i, child)){
            break;//如果i的权小于child的权, 则i已经到了合适的位置
        }
        Swap(heap, i, child);
        i = child;
        child = LeftChild(i);
    }
}

//插入一个结点
void InsertNode(MinHeap heap, HuffmanNode node){
    heap->array[heap->size++] = node;
    PercolateUp(heap, heap->size-1);
}

//得到min heap中权值最小的结点， 并将其从堆中删除
HuffmanNode PopMin(MinHeap heap){
    HuffmanNode res = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->size--;
    PercolateDown(heap, 0);
    return res;
}

//计算文本中字符的频率, 并返回字符的种数
int getFrequency(char* text){
    int num = 0;
    char* currChar = text;
    while(*currChar != '\0'){
        if(Weights[*currChar]++ == 0){
            num++;
        }
        currChar++;
    }
    return num;
}

//构建最小堆
MinHeap BuildMinHeap(char *text){
    charNum = getFrequency(text);

    MinHeap heap = NewHeap(charNum);
    for(int i=0; i<128; i++){
        if(Weights[i] != 0){
            InsertNode(heap, NewNode(i, Weights[i]));
        }
    }
    return heap;
}

//构建huffman tree
HuffmanNode BuildHuffmanTree(char *text){
    HuffmanNode min1, min2, root;
    MinHeap heap = BuildMinHeap(text);

    while(!IsOnlyOne(heap)){
        min1 = PopMin(heap);
        min2 = PopMin(heap);
        root = NewNode('#', min1->weight + min2->weight);
        root->left = min1;
        root->right = min2;
        InsertNode(heap, root);
    }

    free(heap->array);
    free(heap);
    return root;
}

void ShowFrequency(void){
    printf("字符出现的频率如下: \n");
    for(int i=0; i<127; i++){
        if(Weights[i] != 0){
            printf("\"%c\": %d\n", i, Weights[i]);
        }
    }
}

/*     得到Huffman树编码的函数      */

//是否是叶结点
bool IsLeaf(HuffmanNode node){
    return !(node->left || node->right);
}

void PrintArr(int* arr, int len){
    for(int i=0; i<len; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void PrintCodes(HuffmanNode root, int* arr, int depth){
    if(IsLeaf(root)){
        printf("\"%c\": ", root->key);
        PrintArr(arr, depth);
    }
    if(root->left){
        arr[depth] = 0;
        PrintCodes(root->left, arr, depth+1);
    }
    if(root->right){
        arr[depth] = 1;
        PrintCodes(root->right, arr, depth+1);
    }
}

/*     生成Markdown绘图代码     */
// static int num = 1;//计数器， 用于生成结点编号
// void NumIfy(HuffmanNode root){
//     root->num = num;
//     if(!IsLeaf(root)){
//         num++;
//         NumIfy(root->left);
//         num++;
//         NumIfy(root->right);
//     }
// }
// void getGraph(HuffmanNode root){//生成Markdown绘图代码
//     if(IsLeaf(root)){
//         return;
//     }
//     printf("%d((%c %d)) --> %d((%c %d))\n", root->num, root->key, root->weight, root->left->num, root->left->key, root->left->weight);
//     printf("%d((%c %d)) --> %d((%c %d))\n", root->num, root->key, root->weight, root->right->num, root->right->key, root->right->weight);
//     getGraph(root->left);
//     getGraph(root->right);
// }

void HuffmanCoding(char* text){
    HuffmanNode root = BuildHuffmanTree(text);
    // NumIfy(root);
    // getGraph(root);
    int arr[charNum];
    PrintCodes(root, arr, 0);
}


int main(void){
    char *text = "Effificient and robust facial landmark localisation is crucial for the deployment of real-time face analysis systems. This paper presents a new loss function, namely Rectifified Wing (RWing) loss, for regression-based facial landmark localisation with Convolutional Neural Networks (CNNs). We fifirst systemically analyse different loss functions, including L2, L1 and smooth L1. The analysis suggests that the training of a network should pay more attention to small-medium errors. Motivated by this finding, we design a piece-wise loss that amplififies the impact of the samples with small-medium errors. Besides, we rectify the loss function for very small errors to mitigate the impact of inaccuracy of manual annotation";
    printf("%d\n", strlen(text));
    HuffmanCoding(text);
    printf("%d\n", charNum);
    // ShowFrequency();
}