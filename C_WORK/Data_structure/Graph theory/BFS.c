//广度优先搜索/Breadth First Search
#include "../Graph theory/graph_set3.c"
#include "../Queue/Linked_Queue.c"

void operation(graph g, Index v){
    printf("%s ", g->vertices[v].Key);
}

void BFS(graph g){
    Queue VertexQ = InitQueue();

    bool Visited[g->vexNum];
    for(int i=0; i<g->vexNum; i++){
        Visited[i] = false;
    }

    EnQueue(VertexQ, 0);
    int VertexIndex;
    Edge tempEdge;
    while(!IsEmpty(VertexQ)){
        VertexIndex = DeQueue(VertexQ);
        if(Visited[VertexIndex]){//应对有环的情况
            continue;
        }
        Visited[VertexIndex] = true;
        operation(g, VertexIndex);

        tempEdge = g->vertices[VertexIndex].head;
        while(tempEdge){
            if(!Visited[tempEdge->dest]){
                EnQueue(VertexQ, tempEdge->dest);
            }
            tempEdge = tempEdge->next;
        }
    }
}

// int main(void){
//     graph g = NewGraph();
//     BFS(g);
// }
