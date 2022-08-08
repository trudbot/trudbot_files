/*
对严蔚敏版本代码（set1)进行进一步的"改进"
*/
#include <stdio.h>
#include <stdlib.h>
#include "../HashTable/HashTable_set1.c"
#define Inf __INT_MAX__

struct graph;
struct VerName;
typedef struct graph* graph;
typedef int** Matrix;
typedef int ElemType;
typedef struct VerName VerName;

struct VerName{
    char name[20];
};

struct graph{
    int verNum;//vertex/顶点的数量
    Matrix arcs;//存放边及权值
    VerName* verNames;//存放顶点点名
    ElemType* vers;//存放顶点值
    HashTable verData;//存放顶点点名对应的索引
};

graph InitGraph(int verNum){
    graph g = (graph)malloc(sizeof(struct graph));
    g->verNum = verNum;
    g->arcs = (Matrix)malloc(sizeof(int *)*verNum);
    for(int i=0; i<verNum; i++){
        int* arr = (int*)malloc(sizeof(int)*verNum);
        for(int j=0; j<verNum; j++){
            arr[j] = Inf;
        }
        g->arcs[i] = arr;
    }
    g->vers = (ElemType*)malloc(sizeof(ElemType)*verNum);
    g->verData = NewHashTbl(300);
    g->verNames = (VerName*)malloc(sizeof(VerName)*verNum);
    return g;
}

graph CreatGraph(void){
    char Name1[20], Name2[20];
    int weight;
    int val;
    int verNum, arcNum;
    printf("输入顶点的数量和边的数量\n");
    scanf("%d %d", &verNum, &arcNum);//输入顶点的数量和边的数量
    graph g = InitGraph(verNum);

    printf("输入顶点的名字和值\n");
    for(int i=0; i<verNum; i++){//进行顶点的名字和值输入
        scanf("%s %d", g->verNames[i].name, &val);
        put(g->verData, g->verNames[i].name, i);
        g->vers[i] = val;
    }

    printf("输入边, 格式为 顶点名1 顶点名2 权值\n");
    int i, j;
    for(int K=0; K<arcNum; K++){
        scanf("%s %s %d", Name1, Name2, &weight);
        i = get(Name1, g->verData);
        j = get(Name2, g->verData);
        g->arcs[i][j] = g->arcs[j][i] = weight;
    }
    return g;
}

void Show(char* ver1, char* ver2, graph g){
    int i = get(ver1, g->verData);
    int j = get(ver2, g->verData);
    int val1 = g->vers[i];
    int val2 = g->vers[j];
    int weight = g->arcs[i][j];
    printf("%s(%d) <--%d--> %s(%d)", ver1, val1, weight, ver2, val2);
}

void ShowAllVertex(graph g){
    for(int i=0; i<g->verNum; i++){
        printf("%s ", g->verNames[i]);
    }
    printf("\n");
}

int main(void){
    graph g = CreatGraph();
    printf("-------\n");
    ShowAllVertex(g);
    Show("verA", "verC", g);
}