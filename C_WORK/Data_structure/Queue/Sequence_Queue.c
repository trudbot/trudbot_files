# include <stdlib.h>
# include <stdio.h>

typedef struct 
{
    int * data;
    int front, rear, capacity;
    int dataLen;
    /* data */
}queue, *Queue;

Queue InitQueue(int len)//创建并初始化一个队列
{
    if(len == 0)
        return NULL;

    queue * p = (Queue)malloc(sizeof(queue));

    p->capacity = len;
    p->data = (int *)malloc(p->capacity*sizeof(int));
    p->rear = -1;
    p->front = 0;
    p->dataLen = 0;
    return p;
}

int IsEmpty(Queue q){
    return q->dataLen == 0;
}

int IsFull(Queue q){
    return q->dataLen == q->capacity;
}

void EnQueue(Queue q, int value){//入队
    if(IsFull(q)){
        printf("队列已满！%d入队失败\n", value);
        return;
    }
    if(q->rear == q->capacity-1)
        q->rear = -1;
    q->data[++q->rear] = value;
    q->dataLen++;
}

int DeQueue(Queue q){//出队
    if(IsEmpty(q)){
        printf("\n队列为空!\n");
        return -1;
    }
    if(q->front >= q->capacity)
        q->front = 0;
    q->dataLen--;
    return q->data[q->front++];
}

void MakeEmpty(Queue q){
    while(! IsEmpty(q))
        DeQueue(q);
}

int main(void){
    Queue q = InitQueue(10);
    for(int i=0; i<11; i++)
        EnQueue(q, i);
    MakeEmpty(q);
    for(int i=0; i<2; i++)
        printf("%d ", DeQueue(q));
    free(q->data);
    free(q);
}
