# include <stdlib.h>
# include <stdio.h>

typedef struct QNode 
{
    int val;
    struct QNode* next;
}node, *Node;

typedef struct{
    Node head;
    Node rear;
}queue, *Queue;

Node NewNode(void){
    Node p = (Node)malloc(sizeof(node));
    p->next = NULL;
    p->val = 0;
    return p;
}

Queue InitQueue(void){
    Queue q = (Queue) malloc(sizeof(queue));
    q->head = NewNode();
    q->rear = q->head;
    return q;
}

int IsEmpty(Queue q){
    return q->head->next == NULL;
}

int IsJustOne(Queue q){
    return q->head->next == q->rear;
}

void MakeEmpty(Queue q){
    q->rear = q->head->next;
    while(q->rear){
        Node temp = q->rear;
        q->rear = temp->next;
        free(temp);
    }
    q->head->next = NULL;
}

void EnQueue(Queue q, int value){
    q->rear->next = NewNode();
    q->rear = q->rear->next;
    q->rear->val = value;
}

int DeQueue(Queue q){
    int tempInt;
    if(IsEmpty(q)){
        printf("\nQueue is empty\n");
        tempInt = -1;

    }else if(IsJustOne(q)){
        tempInt = q->rear->val;
        free(q->rear);
        q->rear = q->head;
        q->head->next = NULL;

    }else{
        Node tempNode = q->head->next;
        q->head->next = tempNode->next;
        tempInt = tempNode->val;
        free(tempNode);
    }
    return tempInt;
}

// int main(void){
//     Queue q = InitQueue();
//     for(int i=1; i<=1; i++)
//         EnQueue(q, i);
//     for(int i=0; i<5; i++)
//         printf("%d ", DeQueue(q));
//     free(q->head);
//     free(q);
// }

