/*
分离链接法
把散列到同一个值的所有元素保留在一个表中
这个表可以是链表、二叉查找树甚至是另一个散列表
本程序采用链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MinTableSize 100

struct node;
struct HashTbl;
typedef struct HashTbl* HashTable;
typedef struct node* Node;
typedef int __ElemType;

struct node{
    char Key[10];
    __ElemType elem;
    Node next;
};

struct HashTbl{
    int size;
    Node* List;
};

Node NewNode(char *Key, __ElemType Val){
    Node n = (Node)malloc(sizeof(struct node));
    n->next = NULL;
    strncpy(n->Key, Key, 10);
    n->elem = Val;
    return n;
}

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

HashTable NewHashTbl(int size){
    if(size < MinTableSize){
        printf("size too small");
        return NULL;
    }
    size = NextPrime(size);//质数能让哈希函数表现的更好

    HashTable H = (HashTable)malloc(sizeof(struct HashTbl));
    if(!H){
        return NULL;
    }

    H->size = size;

    H->List = (Node*)malloc(sizeof(Node)*size);
    if(!H->List){//不设立头结点
        free(H);
        return NULL;
    }

    for(int i=0; i<size; i++){
        H->List[i] = NULL;
    }

    return H;
}

int Hash(const char* Key, int TableSize){//最核心的哈希函数, 抄过来的同时稍微改了一下， 只计算前十位
    unsigned int Hashval = 0;
    for(int i=0; i<10; i++){
        if(*Key == '\0'){
            break;
        }
        Hashval = (Hashval << 5) + *Key++;
    }
    return Hashval % TableSize;
}

Node Find(char* Key, HashTable H){
    int index = Hash(Key, H->size);
    Node p = H->List[index];

    while(p != NULL && strcmp(p->Key, Key) != 0){
        p = p->next;
    }
    return p;
}

void put(HashTable H, char* Key, __ElemType Val){
    int index = Hash(Key, H->size);
    if(!H->List[index]){
        H->List[index] = NewNode(Key, Val);
    }
    else{//采用分离链接法处理冲突
        Node p = H->List[index];
        while(p){
            if(strcmp(p->Key, Key) == 0){
                p->elem = Val;
                return;
            }
            else if(!p->next){
                break;
            }
            p = p->next;
        }
        p->next = NewNode(Key, Val);
    }
}

__ElemType get(char *Key, HashTable H){
    Node p = Find(Key, H);
    if(p){
        return p->elem;
    }
    else{
        return 0;
    }
}

void Remove(HashTable H, char* Key){
    int index = Hash(Key, H->size);
    Node p = H->List[index];
    if(!p){
        return;
    }
    else if(strcmp(Key, p->Key) == 0){
        H->List[index] = NULL;
        return;
    }else{
        while(p->next){
            if(strcmp(p->next->Key, Key) == 0){
                p->next = p->next->next;
                return;
            }else{
                p = p->next;
            }
        }
    }
}

HashTable FreeHash(HashTable H){
    Node curr, temp;
    for(int i=0; i<H->size; i++){
        curr = H->List[i];
        while(curr != NULL){
            temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(H);
    return NULL;
}


// int main(void){
//     HashTable H = NewHashTbl(500);
//     printf("%d\n", H->size);
//     put(H, "hello", 1000);
//     printf("%d\n", get("hello", H));
//     Remove(H, "hello");
//     printf("%d", get("hello", H));
// }

