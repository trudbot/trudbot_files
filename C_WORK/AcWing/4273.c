/*
给定两个单链表 L1=a1→a2→…→an−1→an 和 L2=b1→b2→…→bm−1→bm，满足：n≥2m。
你的任务是将较短的那个链表逆序，然后将之并入较长的链表，得到形如 a1→a2→bm→a3→a4→bm−1… 的结果。
例如给定两个链表分别为 6→7 和 1→2→3→4→5，你应该输出 1→2→7→3→4→6→5。
补充
本题中可能包含不在两个单链表中的节点，这些节点无需考虑。

输入格式
输入首先在第一行中给出两个链表 L1 和 L2 的头结点的地址，以及正整数 N，即给定的结点总数。
一个结点的地址是一个 5 位数的非负整数（可能包含前导 0），空地址 NULL 用 −1 表示。
随后 N 行，每行按以下格式给出一个结点的信息：
Address Data Next
其中 Address 是结点的地址，Data 是不超过 105 的正整数，Next 是下一个结点的地址。

题目保证没有空链表，并且较长的链表至少是较短链表的两倍长。

输出格式
按顺序输出结果链表，每个结点占一行，格式与输入相同。

数据范围
1≤N≤105
输入样例：
00100 01000 7
02233 2 34891
00100 6 00001
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
00001 7 -1
输出样例：
01000 1 02233
02233 2 00001
00001 7 34891
34891 3 10086
10086 4 00100
00100 6 00033
00033 5 -1
*/

#include <stdio.h>

typedef struct linkNode
{
    int val;
    int next;
}node;

node Link[100001];//题目数据量最大为100000

//数据的输入
void Input(int N){
    int address, val, next;
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &address, &val, &next);
        Link[address].next = next;
        Link[address].val = val;
    }
}

//逆转链表
int reverse(int start){
    int curr, temp;
    curr = Link[start].next;
    Link[start].next = -1;
    while(curr != -1){
        temp = Link[curr].next;
        Link[curr].next = start;
        start = curr;
        curr = temp;
    }
    return start;
}

//获取长度
int getLen(int start){
    int len = 0;
    while(start != -1){
        len++;
        start = Link[start].next;
    }
    return len;
}

int Merge(int head1, int head2, int N){
    int len = getLen(head1);
    if(len > N/3){//维护head1链表为较短的那一条
        int temp = head1;
        head1 = head2;
        head2 = temp;
    }

    head1 = reverse(head1);//将head1链表反转

    //合并部分
    int curr, temp;
    curr = Link[head2].next;
    while(head1 != -1){
        temp = head1;
        head1 = Link[head1].next;
        Link[temp].next = Link[curr].next;
        Link[curr].next = temp;
        curr = Link[temp].next;
        curr= Link[curr].next;//curr向后移三步
    }
    return head2;
}

//打印链表
void PrintLink(int start){
    while(start != -1){
        printf("%05d ", start);
        printf("%d ", Link[start].val);
        if(Link[start].next == -1){
            printf("-1\n");
        }else{
            printf("%05d\n", Link[start].next);
        }
        start = Link[start].next;
    }
}

int main(void){
    int head1, head2, N;
    scanf("%d %d %d", &head1, &head2, &N);
    Input(N);
    PrintLink(Merge(head1, head2, N));
}

