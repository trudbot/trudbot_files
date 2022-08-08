/*
图的存储之邻接矩阵(adjacent matrix)
以带权值的无向图举例
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Data_structure/HashTable_set1.c"
#define Inf __INT_MAX__

struct graph;
typedef struct graph* graph;
typedef int** Matrix;
typedef int ElemType;

struct graph{
    int verNum;//vertex/顶点的数量
    Matrix arcs;//
    ElemType* vers;//存放结点值
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
    return g;
}

graph CreatGraph(void){
    HashTable H = NewHashTbl(300);
    char Name1[20], Name2[20];
    int weight;
    int verNum, arcNum;
    printf("输入顶点的数量和边的数量\n");
    scanf("%d %d", &verNum, &arcNum);//输入顶点的数量和边的数量
    graph g = InitGraph(verNum);

    printf("输入顶点的名字和值\n");
    for(int i=0; i<verNum; i++){//进行顶点的名字和值输入
        scanf("%s %d", Name1, &g->vers[i]);
        put(H, Name1, i);
    }

    printf("输入边, 格式为 顶点名1 顶点名2 权值\n");
    int i, j;
    for(int K=0; K<arcNum; K++){
        scanf("%s %s %d", Name1, Name2, &weight);
        i = get(Name1, H);
        j = get(Name2, H);
        g->arcs[i][j] = g->arcs[j][i] = weight;
    }
    free(H);
    return g;
}

int main(void){
    graph g = CreatGraph();
    printf("%d <-%d-> %d", g->vers[0], g->arcs[0][1], g->vers[1]);
}
