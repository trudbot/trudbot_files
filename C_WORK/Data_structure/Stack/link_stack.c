# include <stdio.h>
# include <stdlib.h>

typedef struct link
{
    int elem;
    struct link* next;
    /* data */
}link, *Stack;

link* creat_node()
{
    link*p = (link*)malloc(sizeof(link));
    p->next = NULL;
    return p;
} 

void push(link* head, int value)
{
    link* p = creat_node();
    p->elem = value;
    p->next = head->next;
    head->next = p;
}

int pop(link* head)
{
    if(! head->next){
        printf("\n栈是空的!\n");
        return -1;
    }
    int value;
    link*temp = head->next;
    head->next = temp->next;
    value = temp->elem;
    free(temp);
    return value;
}

int IsEmpty(Stack head){
    return head->next == NULL;
}

void MakeEmpty(link *head){
    while(! IsEmpty(head))
    {
        pop(head);
    }
}

int main(void)
{
    link* head = creat_node();
    for(int i=1; i<=10; i++)
        push(head, i);
    MakeEmpty(head);
    printf("%d  ", pop(head));
    free(head);
}