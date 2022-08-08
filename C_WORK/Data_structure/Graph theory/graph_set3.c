//Created by 宋遗平 on 2022/5/30
//图的邻接表表示法(adjacency list)
//仍以无向图举例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../Data_structure/HashTable_set1.c"
#define ERROR_INDEX __INT_MAX__
#define Max_VerNum 230

typedef char KeyType;
typedef int DataType;
typedef unsigned int Index;

typedef enum bool{
    false, true
}bool;

//边结构体
typedef struct node{
    Index dest;//边的另一个顶点的索引
    int weight;//存放权值
    struct node* next;
}*Edge;

//顶点结构体
typedef struct{
    char Key[20];
    Edge head;
}Vertex;

//图结构体
typedef struct graph{
    int vexNum;
    Vertex vertices[Max_VerNum];
}*graph;

//初始化边结点
Edge NewEdge(Index dest){
    Edge e = (Edge)malloc(sizeof(struct node));
    e->dest = dest;
    e->next = NULL;
    return e;
}

void AddNode(graph g, Index curr, Index dest){
    Edge edge = NewEdge(dest);
    edge->next = g->vertices[curr].head;
    g->vertices[curr].head = edge;
}

void AddWeightNode(graph g, Index curr, Index dest, int weight){
    Edge edge = NewEdge(dest);
    edge->next = g->vertices[curr].head;
    edge->weight = weight;
    g->vertices[curr].head = edge;
}

//增加顶点
void AddVertex(graph g, char* key){
    strcpy(g->vertices[g->vexNum].Key, key);
    g->vertices[g->vexNum].head = NULL;
    g->vexNum++;
}

//根据键值获得下标
Index Locate(graph g, char* key){
    for(int i=0; i<g->vexNum; i++){
        if(0 == strcmp(g->vertices[i].Key, key)){
            return i;
        }
    }
    return ERROR_INDEX;
}

//增加一条无向边边
void AddUndirectedEdge(graph g, char* v1, char* v2){
    Index v1Index = Locate(g, v1);
    Index v2Index = Locate(g, v2);
    if(v1Index == ERROR_INDEX || v2Index == ERROR_INDEX){
        return;
    }
    AddNode(g, v1Index, v2Index);
    AddNode(g, v2Index, v1Index);
}

//增加一条有向边
void AddDirectedEdge(graph g, char* v1, char* v2){
    Index v1Index = Locate(g, v1);
    Index v2Index = Locate(g, v2);
    if(v1Index == ERROR_INDEX || v2Index == ERROR_INDEX){
        return;
    }
    AddNode(g, v1Index, v2Index);
}

void AddDirectedWeightedEdge(graph g, char* v1, char* v2, int weight){
    Index v1Index = Locate(g, v1);
    Index v2Index = Locate(g, v2);
    if(v1Index == ERROR_INDEX || v2Index == ERROR_INDEX){
        return;
    }
    AddWeightNode(g, v1Index, v2Index, weight);
}

graph NewGraph(void){
    graph g = (graph)malloc(sizeof(struct graph));
    g->vexNum = 0;
    AddVertex(g, "V1");
    AddVertex(g, "V2");
    AddVertex(g, "V3");
    AddVertex(g, "V4");
    AddVertex(g, "V5");
    AddVertex(g, "V6");
    AddVertex(g, "V7");
    AddVertex(g, "V8");

    AddUndirectedEdge(g, "V1", "V2");
    AddUndirectedEdge(g, "V1", "V3");
    AddUndirectedEdge(g, "V3", "V6");
    AddUndirectedEdge(g, "V3", "V7");
    AddUndirectedEdge(g, "V6", "V7");
    AddUndirectedEdge(g, "V2", "V5");
    AddUndirectedEdge(g, "V2", "V4");
    AddUndirectedEdge(g, "V5", "V8");
    AddUndirectedEdge(g, "V4", "V8");
    return g;
}

graph NewDirectedGraph(void){
    graph g = (graph)malloc(sizeof(struct graph));
    g->vexNum = 0;

    AddVertex(g, "V1");
    AddVertex(g, "V2");
    AddVertex(g, "V3");
    AddVertex(g, "V4");
    AddVertex(g, "V5");
    AddVertex(g, "V6");
    AddVertex(g, "V7");
    AddVertex(g, "V8");
    AddVertex(g, "V9");
    AddVertex(g, "V10");
    AddVertex(g, "V11");

    AddDirectedEdge(g, "V1", "V4");
    AddDirectedEdge(g, "V2", "V4");
    AddDirectedEdge(g, "V2", "V5");
    AddDirectedEdge(g, "V3", "V6");
    AddDirectedEdge(g, "V4", "V7");
    AddDirectedEdge(g, "V6", "V8");
    AddDirectedEdge(g, "V7", "V8");
    AddDirectedEdge(g, "V6", "V9");
    AddDirectedEdge(g, "V7", "V9");
    AddDirectedEdge(g, "V7", "V10");
    AddDirectedEdge(g, "V8", "V11");
    return g;
}

graph DirectedWeightedGraph(void){
    graph g = (graph)malloc(sizeof(struct graph));
    g->vexNum = 0;
    //图为数据结构与算法分析236页图9-20
    AddVertex(g, "V1");
    AddVertex(g, "V2");
    AddVertex(g, "V3");
    AddVertex(g, "V4");
    AddVertex(g, "V5");
    AddVertex(g, "V6");
    AddVertex(g, "V7");

    AddDirectedWeightedEdge(g, "V1", "V4", 1);
    AddDirectedWeightedEdge(g, "V1", "V2", 2);
    AddDirectedWeightedEdge(g, "V3", "V1", 4);
    AddDirectedWeightedEdge(g, "V4", "V3", 2);
    AddDirectedWeightedEdge(g, "V3", "V6", 5);
    AddDirectedWeightedEdge(g, "V2", "V4", 3);
    AddDirectedWeightedEdge(g, "V4", "V6", 8);
    AddDirectedWeightedEdge(g, "V2", "V5", 10);
    AddDirectedWeightedEdge(g, "V4", "V5", 2);
    AddDirectedWeightedEdge(g, "V4", "V7", 4);
    AddDirectedWeightedEdge(g, "V7", "V6", 1);
    AddDirectedWeightedEdge(g, "V5", "V7", 6);
    return g;
}


void PrintGraph(graph g){
    Edge edge;
    for(int i=0; i<g->vexNum; i++){
        printf("%s的邻接点有: ", g->vertices[i].Key);
        edge = g->vertices[i].head;
        while(edge){
            printf("%s ", g->vertices[edge->dest].Key);
            edge = edge->next;
        }
        printf("\n");
    }
}



// int main(void){
//     graph g = NewGraph();
//     DFSTraverse(g);
//     PrintGraph(g);
// }