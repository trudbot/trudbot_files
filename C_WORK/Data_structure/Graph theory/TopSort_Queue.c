#include "../Graph theory/graph_set3.c"
#include "../Queue/Linked_Queue.c"

void getIndegree(graph g, Index* Indegree){
    Edge edge;
    for(int i=0; i<g->vexNum; i++){
        Indegree[i] = 0;
    }
    for(int i=0; i<g->vexNum; i++){
        edge = g->vertices[i].head;
        while(edge){
            Indegree[edge->dest]++;
            edge = edge->next;
        }
    }
}

void TopSort(graph g){
    int counter = 0;
    Index curr;
    int Indegree[g->vexNum];
    Edge edge;
    getIndegree(g, Indegree);

    Queue vexQ = InitQueue();
    for(int i=0; i<g->vexNum; i++){
        if(Indegree[i] == 0){
            EnQueue(vexQ, i);
        }
    }

    while(!IsEmpty(vexQ)){
        curr = DeQueue(vexQ);
        printf("%s ", g->vertices[curr].Key);
        counter++;

        edge = g->vertices[curr].head;
        while(edge){
            if(--Indegree[edge->dest] == 0){
                EnQueue(vexQ, edge->dest);
            }
            edge = edge->next;
        }
    }
    if(counter != g->vexNum){
        printf("graph has a cycle");
    }
}

int main(void){
    graph g = NewDirectedGraph();
    TopSort(g);
}