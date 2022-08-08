/*
处理哈希值冲突的第二种方法
开放寻址法
思想是哈希表中每个单元只放一个元素， 当产生冲突时， 用一定的手段， 在表中找另一个空单元来存放冲突的元素

公式为 h(x) = (Hash(x) + F(i)) % TableSize, 其中F(i)就是解决冲突的关键函数
当发生冲突值， 会用F(i)得到新的散列值， 直到找到空单元

1、线性探测法
F(i)是关于i的线性函数， 如F(i) = i
即在冲突的单元往后线性探测非空单元
很大的问题是， 冲突的数量增多时， 冲突的元素占据的单元会形成一些区块， 称为“一次聚集”
当正常的单元散列到区块中时， 都要经过多次试选单元才能找到空单元， 查找也是如此。

2、平方探测法
顾名思义， 平方探测法就是F(i)是关于i的二次函数
常用F(i) = i^2
发生冲突时， 新的哈希值是h(x) = (Hash(x) + i^2)%TableSize, i=1、2、3……
一个严重的问题是， 当哈希表比较满时， 使用平方探测法不一定能找到空单元
相关的定理是：若表的大小是素数， 且表至少有一半是空的时， 总能使用平方探测法找到空单元
平方探测法虽然排除了一次聚集， 但却带来了二次聚集。散列到同一位置的元素， 它的备选单元始终是相同的。

3.双散列
双散列弥补了平方探测法二次聚集的缺陷
回顾一下开放寻址的基本公式： h(x) = (Hash(X) + F(i)) mod TableSize, 变化i直到找到空单元
在平方探测法中， 散列到同一个值的两个元素的预选单元总是相同的， 即使两个元素的Key不同， 这就导致了二次聚集
而双重散列的思想则是， 在发生冲突时， 将第二个散列函数运用于键， 让散列到同一个值的元素有不同的预选单元
常用的选择是 F(i) = i*Hash2(X)
可以发现， Hash2(X)的值就是查找预选单元时的步长， 所以Hash2(X)的选择至关重要， 它的值域不能太大也不能太小


采用开放寻址的哈希表在删除上有些特殊， 不能直接删除， 因为此单元可能发生过冲突， 冲突元素绕过它存在了别处
而要找到冲突元素的话， 当前这个冲突单元就不能为空。
因此在这里采用惰性删除

本程序采用平方探测
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MinTableSize 200

struct node;
struct HashTbl;
enum KindOfCell;
typedef struct node Cell;
typedef struct HashTbl* HashTable;
typedef enum KindOfCell Kind;
typedef unsigned int Index;
typedef int ElemType;
typedef char KeyType;

enum KindOfCell{
    Legitimate, Empty, Deleted
};

struct node{
    ElemType val;
    KeyType Key[10];
    Kind info;
};

struct HashTbl{
    int size;
    Cell* Cells;
};

int IsPrime(int i)
{
    int j;

    if (i == 2 || i==3)
        return 1;
    if (i%6 != 1 && i%6 != 5)
        return 0;
    
    for (j = 5; j<= (int)sqrt(i); j++)
        if (i%j == 0 || i%(j+2) == 0)
            return 0;
    if (j == (int)sqrt(i))
        return 1;
    return 1;
}

int NextPrime(int n){
    while(!IsPrime(n)){
        n++;
    }
    return n;
}

HashTable InitTable(int TableSize){
    TableSize = NextPrime(TableSize);
    //内存分配
    HashTable H = (HashTable)malloc(sizeof(struct HashTbl));
    if(!H){
        return NULL;
    }
    H->size = TableSize;
    H->Cells = (Cell*)malloc(sizeof(Cell)*TableSize);
    if(!H->Cells){
        free(H);
        return NULL;
    }
    //初始化
    for(int i=0; i<TableSize; i++){
        H->Cells[i].val = 0;
        H->Cells[i].info = Empty;
    }
    return H;
}

Index Hash(const char* Key, int TableSize){
    unsigned int Hashval = 0;
    for(int i=0; i<10; i++){
        if(*Key == '\0'){
            break;
        }
        Hashval = (Hashval << 5) + *Key++;
    }
    return Hashval % TableSize;
}

Index Find(HashTable H, char *Key){//可能陷入死循环
    Index pos;
    int collisionNum = 0;

    pos = Hash(Key, H->size);
    while(H->Cells[pos].info == Legitimate){
        pos += 2* ++collisionNum -1;//实现平方的方式很巧妙
        if(pos >= H->size){
            pos -= H->size;
        }
    }
    return pos;
}

Index FindKey(HashTable H, char* Key){
    Index pos;
    int collisionNum = 0;

    pos = Hash(Key, H->size);
    while(H->Cells[pos].info != Empty){
        if(strcmp(H->Cells[pos].Key, Key) == 0 && H->Cells[pos].info == Legitimate){
            return pos;
        }
        pos += 2* ++ collisionNum - 1;
        if(pos >= H->size){
            pos -= H->size;
        }
    }
    return H->size;
}

void Insert(HashTable H, char* Key, ElemType Val){//由于一些问题， Insert没有考虑更新键值对
    Index pos = Find(H, Key);
    if(H->Cells[pos].info != Legitimate){
        H->Cells[pos].val = Val;
        strcpy(H->Cells[pos].Key, Key);
        H->Cells[pos].info = Legitimate;
    }
}



ElemType get(HashTable H, char* Key){
    Index pos = FindKey(H, Key);
    if(pos == H->size){
        return -1;
    }else{
        return H->Cells[pos].val;
    }
}

void Delete(HashTable H, char* Key){
    Index pos = FindKey(H, Key);
    if(pos != H->size){
        H->Cells[pos].info = Deleted;
    }
}


// int main(void){
//     HashTable H = InitTable(400);
//     Insert(H, "hello", 100);
//     Insert(H, "world", 400);
//     printf("%d\n", get(H, "hello"));
//     Delete(H, "hello");
//     printf("%d\n", get(H, "hello"));
// }