//Created by 宋遗平 on 2022/6/11
//带权图单源最短路径问题之Dijkstra算法

#include "graph_set3.c"
#define INF __INT_MAX__
#define NotAVertex -1

typedef struct{
    Index path;
    bool Known;
    unsigned distance;
}Table;

int FindMin(Table Tab[], int len){
    int i;
    int min = INF, mini;
    for(i=0; i<len; i++){
        if(!Tab[i].Known && Tab[i].distance < min){
            min = Tab[i].distance;
            mini = i;
        }
    }
    if(min == INF){
        return NotAVertex;
    }
    return mini;
}

void Dijkstra(graph g, Index s, Table Tab[]){
    int vexNum = g->vexNum;
    Index currVex;
    Edge edge;

    Tab[s].distance = 0;//s到自身的最短距离为0
    Tab[s].path = s;

    while(true){
        currVex = FindMin(Tab, vexNum);
        if(currVex == NotAVertex){
            break;
        }

        Tab[currVex].Known = true;
        edge = g->vertices[currVex].head;
        while(edge){
            if(edge->weight + Tab[currVex].distance < Tab[edge->dest].distance){
                Tab[edge->dest].distance = edge->weight + Tab[currVex].distance;
                Tab[edge->dest].path = currVex;
            }
            edge = edge->next;
        }
    }
}

void PrintShortestDist(Index s, Table tab[], graph g){
    char* start = g->vertices[s].Key;
    printf("--%s到各顶点最短距离如下--\n", start);
    for(int i=0; i<g->vexNum; i++){
        if(i == s){
            continue;
        }
        printf("  %s到%s的最短距离为%d\n", start, g->vertices[i].Key, tab[i].distance);
    }
    printf("--------------------------\n");
}

void PrintPath(graph g, Index v, Table tab[]){
    if(tab[v].path != NotAVertex){
        PrintPath(g, tab[v].path, tab);
        printf(" --> ");
    }
    printf("%s", g->vertices[v].Key);
}

void ShowPath(graph g, Table Tab[], Index start, Index end){
    Tab[start].path = NotAVertex;
    printf("%s到%s的最短路径为: ", g->vertices[start].Key, g->vertices[end].Key);
    PrintPath(g, end, Tab);
    printf("\n");
}

void ShortestPath(graph g, char* vex){
    Index v = Locate(g, vex);
    Table Tab[g->vexNum];
    for(int i=0; i<g->vexNum; i++){
        Tab[i].path = NotAVertex;
        Tab[i].Known = false;
        Tab[i].distance = INF;
    }
    Dijkstra(g, v, Tab);
    PrintShortestDist(v, Tab, g);
    
    for(int i=0; i<g->vexNum; i++){
        if(i == v){
            continue;
        }
        ShowPath(g, Tab, v, i);
    }
}

int main(void){
    graph g = DirectedWeightedGraph();
    ShortestPath(g, "V1");
}

