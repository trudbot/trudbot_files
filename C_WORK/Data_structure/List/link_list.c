/*
Created by 宋遗平 on 20022/04/22
Topic: 单链表的相关操作
Notice: 1.文件中设计的函数和操作均面向与有头结点(不放数据）的链表
        2.文件中涉及的排序均为非降序
*/
#ifndef LINKLISTEPIC
#define LINKLISTEPIC

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <windows.h>

//------------------------链表的基本部分------------------------------------
typedef struct linkNode
{
    int elem;
    struct linkNode* next;
}node, *Node;

typedef Node linkList;

Node NewNode(void){//创建新结点
    Node temp = (Node)malloc(sizeof(node));
    temp->elem = 0;
    temp->next = NULL;
    return temp;
}

void append(linkList head, Node target){//尾插法插入结点
    while(head->next){
        head = head->next;
    }
    head->next = target;
}

void first(linkList head, Node target){//头插法插入结点
    target->next = head->next;
    head->next = target;
}

void CreatLink(Node head, int len){//创建指定长度的链表， 未初始化
    for(int i=0; i<len; i++){
        Node temp = NewNode();
        first(head, temp);
    }
}

int DelNode(linkList head, int value){
    while(head->next){
        if(head->next->elem == value)
        {
            Node temp = head->next;
            head->next = temp->next;
            free(temp);
            return 1;
        }
        head = head->next;
    }
    return 0;
}

Node FindNode(linkList head, int value){
    Node p = head->next;
    while(p!=NULL && p->elem!=value){
        p = p->next;
    }
    return p;
}

int GetLen(linkList head)
{
    Node t = head;
    while(t->next)
    {
        head->elem++;
        t = t->next;
    }
    return head->elem;
}

void ShowList(linkList head){//打印链表
    head = head->next;
    if(!head){
        printf("[]\n");
        return;
    }
    printf("[");
    while(head->next){
        printf("%d->", head->elem);
        head = head->next;
    }
    printf("%d]\n", head->elem);
}

void Free(linkList head){//释放链表内存
    Node temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}

//----------------------------一些辅助函数--------------------------------------

void randomlist(linkList head){//将传入的链表初始化（随机数）
    srand((unsigned int)1000);
    while (head->next)
    {
        head = head->next;
        head->elem = rand()%1000000;
    }
}

typedef enum{
    false = 0, true
}bool;


//-----------------------------链表逆转---------------------------------


void reverse_1(linkList head){//三指针迭代逆转, 传入链表头节点
    if(!head->next){
        return;
    }
    Node slow, mid, fast;

    slow = NULL, mid = head->next, fast = mid->next;

    while(fast){
        mid->next = slow;
        slow = mid;
        mid = fast;
        fast = mid->next;
    }

    mid->next = slow;
    head->next = mid;
}

void reverse_2_1(linkList head){//头插法逆转链表
    Node new_head, curr, temp;
    curr = head->next;
    new_head->next = NULL;

    while(curr){
        temp = curr;
        curr = head->next;
        temp->next = new_head->next;
        new_head->next = temp;
    }
    head->next = new_head->next;
}

void reverse_2_2(linkList head){
    Node i = head->next, temp;
    head->next = NULL;

    while(i){
        temp = i;
        i = i->next;
        first(head, temp);
    }
}

linkList reverse_3(Node last, Node now){//自研递归， last参数固定为NULL, now传入链表的首元节点
    if(!now->next || !now){
        now->next = last;
        return now;
    }else{
        Node temp = reverse_3(now, now->next);
        now->next = last;
        return temp;
    }
}

linkList reverse_4(Node head){//经典递归， 传入链表的首元节点
    if(!head->next || !head){
        return head;
    }else{
        Node temp = reverse_4(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
}

//------------------------------合并两个有序链表----------------------------------

linkList MergeLink_1(linkList link1, linkList link2){//递归合并, 时间复杂度O(n+m)； 空间复杂度为O(n+m), 十万级排序时出现了爆栈的情况
    if(!link1)
        return link2;
    else if(!link2)
        return link1;
    else{
        if(link1->elem < link2->elem)
        {
            link1->next = MergeLink_1(link1->next, link2);
            return link1;
        }
        else
        {
            link2->next = MergeLink_1(link1, link2->next);
            return link2;
        }
    }
}

linkList MergeLink_2(linkList link1, linkList link2){//迭代合并， 空间复杂度为O(1), 时间复杂度为O(n+m)
    Node head = NewNode();
    Node tail = head;//结果链的最后尾节点
    Node i = link1, j = link2;

    while(i && j){
        if(i->elem <= j->elem){
            tail->next = i;
            tail = tail->next;
            i = i->next;

        }
        else{
            tail->next = j;
            tail = tail->next;
            j = j->next;
        }
    }
    if(i == NULL){
        tail->next = j;
    }else{
        tail->next = i;
    }

    tail = head->next;
    free(head);
    return tail;
}


//------------------------------链表的排序----------------------------------------


void LinkSort_1(linkList head){//自写插入排序
    Node i = head->next;
    head->next = NULL;//将头与数据分离
    Node temp, j;

    while(i){
        temp = i;
        i = i->next;
        j = head;
        while(j->next && j->next->elem <= temp->elem)//查找插入位置
            j = j->next;
        temp->next = j->next;
        j->next = temp;
    }
}

void LinkSort_2(Node head){//力扣官方插入排序， 在效率上有一定提升
    if(!head->next)
        return;
    Node curr, tail, temp;
    tail = head->next;//tail为已排序部分的最后一个结点
    curr = tail->next;

    while(curr){//curr为当前要插入的结点
        if(curr->elem >= tail->elem)
        {
            tail = tail->next;//无需操作， tail直接后移
        }
        else
        {
            temp = head;
            while(temp->next->elem <= curr->elem)//从头开始查找curr的插入位置
            {
                temp = temp->next;
            }
            tail->next = curr->next;//将curr从链表中抽出
            curr->next = temp->next;//将curr插入链表
            temp->next = curr;
        }
        curr = tail->next;//tail下一个结点始终是未排序部分的第一个结点
    }
}

//自顶向下(递归实现)归并排序, 以下两个归并排序获取中间结点的算法不同.时间复杂度O(nlog n), 空间复杂度O(log n)
linkList LinkMergeSort_1_sub(linkList head, int len){//自写归并排序, 获取链表长度以找到中间结点
    if(!head->next)
        return head;
    Node temp = head;
    for(int i=0; i<len/2-1; i++){
        temp = temp->next;
    }
    Node subLink = temp->next;
    temp->next = NULL;
    subLink = LinkMergeSort_1_sub(subLink, len-len/2);
    head = LinkMergeSort_1_sub(head, len/2);
    return  MergeLink_2(head, subLink);
}

void LinkMergeSort_1(linkList head){
    if(!head->next)
        return;
    head->next = LinkMergeSort_1_sub(head->next, GetLen(head));
}

linkList LinkMergeSort_2_sub(linkList head, Node tail){//主流归并排序， 利用快慢指针找到中间结点
    if(head->next == tail){//以tail结点作为链表结束的标志
        head->next = NULL;
        return head;
    }
    Node fast, slow;
    fast = slow = head;
    while(fast != tail && fast->next != tail){
        fast = fast->next->next;
        slow = slow->next;
    }
    head = LinkMergeSort_2_sub(head, slow);
    slow = LinkMergeSort_2_sub(slow, tail);
    return MergeLink_2(head, slow);
}

void LinkMergeSort_2(linkList head){
    if(!head->next)
        return;
    head->next = LinkMergeSort_2_sub(head->next, NULL);
}

//自底向上(迭代实现)归并排序， 时间复杂度为O(nlog n)， 空间复杂度为O(1)
void LinkMergeSort_3(linkList head){//直接传入头结点
    if(!head->next)
        return;
    int i;//循环变量
    Node curr = head->next;
    int length = 0;
    while(curr){//获取链表长度
        length++;
        curr = curr->next;
    }
    Node head1, head2, temp, tail;
    for(int subLen=1; subLen<length; subLen<<=1){
        tail = head;
        curr = head->next;
        while(curr){//每次循环获得两个长度为subLen的子链表， 合并后加入主链表中

            //获取第一个子链表
            head1 = curr;
            for(i=1; i<subLen && curr && curr->next; i++)
                curr = curr->next;//curr将停在第一个子链表最后一个结点
            
            //获取第二个子链表
            head2 = curr->next;
            curr->next = NULL;//切断连接关系， 使第一个子链表独立
            curr = head2;

            for(i=1; i<subLen && curr && curr->next; i++)
                curr = curr->next;
            
            if(curr){//如果curr不为NULL， 则第二个子链表不为空。 使第二个链表独立， 并使curr为下一个结点。
                temp = curr;
                curr = curr->next;
                temp->next = NULL;
            }

            tail->next = MergeLink_2(head1, head2);//合并两个子链表， 并加到主链表尾部
            while(tail->next)
                tail = tail->next;//维护tail为主链表尾部
        }
    }
}

//-----------------------------------判断两个单链表是否相交------------------------------------


bool IsIntersect_1(linkList link1, linkList link2){//若链表相交， 则两链表必存在某个结点地址相同
    Node p1 = link1->next, p2 = link2->next;
    
    while(p1){
        p2 = link2->next;
        while(p2){
            if(p1 == p2)
                return true;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return false;
}//时间复杂度为O(n^2)

//由单链表的特性可知， 若两个单链表相交， 则两链表有相同的长度不为0的尾链
bool IsIntersect_2(linkList link1, linkList link2){//所以两链表相交， 其尾结点必相同
    while(link1->next){
        link1 = link1->next;
    }
    while(link2->next){
        link2 = link2->next;
    }
    if(link1 == link2)
        return true;
    else
        return false;
}//时间复杂度为O(n)

//相交的链表在释放内存时容易带来不安全的问题， 应避免链表相交

//-------------------------------------------------------------------------------
#endif /*LINKLISTEPIC*/

int main(void){
    int size = 1000000;
    long long start, end;
    linkList link = NewNode();
    CreatLink(link, size);

    randomlist(link);
    printf("测试数据量：%d\n", size);
    start = GetTickCount();
    LinkMergeSort_1(link);
    end = GetTickCount();
    printf("排序1, 时间: %lld ms\n", end - start);
    
    randomlist(link);
    start = GetTickCount();
    LinkMergeSort_2(link);
    end = GetTickCount();
    printf("排序2, 时间: %lld ms\n", end - start);

    randomlist(link);
    start = GetTickCount();
    LinkMergeSort_3(link);
    end = GetTickCount();
    printf("排序3, 时间: %lld ms\n", end - start);

    return 0;
}
