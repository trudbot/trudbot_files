# include <stdio.h>
# include <stdlib.h>
# define ERROR -1


typedef struct
{
    int datalen;
    int *data;
    /* data */
}list;

void initlist(list* arr);

int reindex(list *arr, int value);

void append(list *arr, int value);

int insert(list * arr, int index, int value);

int pop(list *arr, int index);

void Free(list* arr);

void print(list *arr);

int main(void)
{
    list nums;
    initlist(&nums);
    for(int i=1; i<=10; i++)
        append(&nums, i);
    insert(&nums, 3, 100);
    pop(&nums, 7);
    print(&nums);
    Free(&nums);
}





void initlist(list* arr)
{
    arr->datalen = 0;
    arr->data = (int *)calloc(1, sizeof(int));
}

void append(list *arr, int value)
{
    arr->data[arr->datalen] = value;
    arr->datalen++;
    arr->data = (int *)realloc(arr->data, sizeof(int)*(arr->datalen+1));
}

int reindex(list *arr, int value)
{
    for(int i=0; i<arr->datalen; i++)
        if(arr->data[i] == value)
            return i;
    return ERROR;
}

int insert(list * arr, int index, int value)
{
    if(index<0 || index>arr->datalen+1)
        return ERROR;
    for(int i=arr->datalen; i>index; i--)
        arr->data[i] = arr->data[i-1];
    arr->data[index] = value;
    arr->datalen++;
    arr->data = (int *)realloc(arr->data, sizeof(int)*(arr->datalen+1));
}

int pop(list *arr, int index)
{
    if(index<0 || index>=arr->datalen)
        return ERROR;
    int value = arr->data[index];
    for(int i=index; i<arr->datalen-1; i++)
        arr->data[i] = arr->data[i+1];
    arr->datalen--;
    arr->data = (int *)realloc(arr->data, sizeof(int)*(arr->datalen+1));
}

void Free(list* arr)
{
    free(arr->data);
}

void print(list *arr)
{
    for(int i=0; i<arr->datalen; i++)
        printf("%d  ", arr->data[i]);
}