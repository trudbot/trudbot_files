/*
Dijkstra 算法是非常著名的贪心算法之一。

它用于解决单源最短路径问题，即指定一个特定源顶点，求该顶点到给定图的所有其他顶点的最短路径。

它由计算机科学家 Edsger W. Dijkstra 于 1956 年构思并在三年后出版。

在该算法中，我们需要不断维护一个包含最短路径树中顶点的集合。

在每一步中，我们找到一个尚未在集合内且与源顶点距离最小的顶点，并将其收于集合中。

因此，通过 Dijkstra 算法，我们可以逐步生成一个有序的顶点序列，我们称之为 Dijkstra 序列。

对于一个给定的图，可能有多个 Dijkstra 序列。

例如，{5,1,3,4,2} 和 {5,3,1,2,4} 都是给定图的 Dijkstra 序列。

注意，序列中的第一个顶点即为指定的特定源顶点。

你的任务是检查给定的序列是否是 Dijkstra 序列。

输入格式
第一行包含两个整数 N 和 M，表示图中点和边的数量。

点的编号 1∼N。

接下来 M 行，每行包含三个整数 a,b,c，表示点 a 和点 b 之间存在一条无向边，长度为 c。

再一行包含整数 K，表示需要判断的序列个数。

接下来 K 行，每行包含一个 1∼N 的排列，表示一个给定序列。

输出格式
共 K 行，第 i 行输出第 K 个序列的判断，如果序列是 Dijkstra 序列则输出 Yes，否则输出 No。

数据范围
1≤N≤1000,
1≤M≤105,
1≤a,b≤N,
1≤c≤100,
1≤K≤100,
保证给定无向图是连通图，
保证无重边和自环（官网没提，但是经实测，官网数据符合此条件）。

输入样例：
5 7
1 2 2
1 5 1
2 3 1
2 4 1
2 5 2
3 5 1
3 4 1
4
5 1 3 4 2
5 3 1 2 4
2 3 4 5 1
3 2 1 5 4
输出样例：
Yes
Yes
Yes
No
*/

#include <stdio.h>
#define MaxVexNum 1000
#define Inf __INT_MAX__

unsigned edge[MaxVexNum+1][MaxVexNum+1];
unsigned Visited[MaxVexNum+1];
unsigned MinDistance[MaxVexNum+1];

void MakeEmpty(int N){
    for(int i=1; i<=N; i++){
        Visited[i] = 0;
        MinDistance[i] = Inf;
    }
}

int IsMin(int v, int N){
    if(Visited[v]){
        return 0;
    }
    for(int i=1; i<=N; i++){
        if(!Visited[i] && MinDistance[i]<MinDistance[v]){
            return 0;
        }
    }
    return 1;
}

void Dijkstra(int start, int N){
    MinDistance[start] = 0;
    Visited[start] = 1;
    for(int j=1; j<=N; j++){
        if(edge[start][j] != 0){
            MinDistance[j] = edge[start][j];
        }
    }
    
    int InputV;
    for(int i=2; i<=N; i++){
        scanf("%d", &InputV);

        //匹配失败
        if(!IsMin(InputV, N)){
            printf("No\n");
            while(++i <= N){
                scanf("%d", &InputV);
            }
            return;
        }

        //
        Visited[InputV] = 1;
        for(int j=1; j<=N; j++){
            if(edge[InputV][j] != 0 && edge[InputV][j]+MinDistance[InputV] < MinDistance[j]){
                MinDistance[j] = edge[InputV][j] + MinDistance[InputV];
            }
        }
    }
    printf("Yes\n");
}

void InputGraph(int M){
    int v1, v2, weight;
    for(int i=0; i<M; i++){
        scanf("%d%d%d", &v1, &v2, &weight);
        edge[v1][v2] = edge[v2][v1] = weight;
    }
}

int main(void){
    int N, M;
    scanf("%d%d", &N, &M);
    InputGraph(M);

    int K, start;
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        scanf("%d", &start);
        MakeEmpty(N);
        Dijkstra(start, N);
    }
}