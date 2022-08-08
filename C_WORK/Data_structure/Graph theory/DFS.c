//深度优先搜索
#include "../Graph theory/graph_set3.c"

//深度优先搜索/ Depth First Search
void DFS(graph g, Index v, bool* Visited){
    Visited[v] = true;
    printf("%s ", g->vertices[v].Key);
    Edge edge = g->vertices[v].head;
    while(edge){
        if(!Visited[edge->dest]){
            DFS(g, edge->dest, Visited);
        }
        edge = edge->next;
    }
}

//深度优先搜索的准备工作
void DFSTraverse(graph g){
    bool Visited[g->vexNum];
    for(int i=0; i<g->vexNum; i++){
        Visited[i] = false;
    }
    DFS(g, 0, Visited);//开始遍历的顶点可以单独指定
    //如果图是不连通的， 可能会有某些顶点不能被访问到
    //可以对每一个未被访问的顶点都进行搜索以解决此问题
    printf("\n");
}

int main(void){
    graph g = NewGraph();
    DFSTraverse(g);
}