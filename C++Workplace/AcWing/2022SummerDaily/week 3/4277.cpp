//
// Created by trudbot on 2022/6/20.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int data, next;
}Node;

Node List[100001];

void Input(int N){
    int address;
    while(N-- > 0){
        cin>> address;
        cin>> List[address].data>>List[address].next;
    }
}

//获得区块最后一个结点的地址, address为区块第一个结点的地址
int getLast(int address, int k){
    for(int i=1; i<k; i++){
        if(List[address].next == -1){
            break;
        }
        else{
            address = List[address].next;
        }
    }
    return  address;
}

int ReverseBlock(int head, int k){
    int tail, curr, temp;
    tail = getLast(head, k);
    curr = List[tail].next;
    List[tail].next = -1;

    while(curr != -1){
        tail = getLast(curr, k);
        temp = List[tail].next;
        List[tail].next = head;
        head = curr;
        curr = temp;
    }
    return head;
}

void PrintLink(int start){
    while(start != -1){
        printf("%05d ", start);
        printf("%d ", List[start].data);
        if(List[start].next == -1){
            printf("-1\n");
        }else{
            printf("%05d\n", List[start].next);
        }
        start = List[start].next;
    }
}

int main() {
    int N, K, head;
    cin>> head>>N >> K;
    Input(N);
    head = ReverseBlock(head, K);
    PrintLink(head);
    return 0;
}
