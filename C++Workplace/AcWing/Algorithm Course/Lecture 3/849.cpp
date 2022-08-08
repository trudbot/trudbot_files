//
// Created by trudbot on 2022/7/7.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 501
#define Inf 1e9
int g[N][N];
int n, m;

int sd[N];
bool vis[N];
int path[N];//记录最短路径中每个顶点的前驱

inline int Find()
{
    int mi, mv = Inf;
    for(int i=1; i<=n; i++)
        if(!vis[i] && sd[i]<mv)
            mv = sd[i], mi = i;
    if(mv == Inf) return -1;
    return mi;
}

void dijkstra(int bg)
{
    for(int i=1; i<=n; i++) sd[i] = Inf;
    sd[bg] = 0;
    path[bg] = bg;
    int curr;
    while(true)
    {
        curr = Find();
        if(curr == -1) break;
        vis[curr] = true;
        for(int i=1; i<=n; i++)
            if(sd[i] > sd[curr]+g[curr][i])
            {
                sd[i] = sd[curr]+g[curr][i];
                path[i] = curr;
            }
    }
}

void PrintPath(int bg, int ta)
{
    if(bg == ta)
    {
        cout << bg;
        return;
    }
    PrintPath(bg, path[ta]);
    cout << "->" << ta;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            g[i][j] = Inf;
    int x, y, v;
    while(m--)
    {
        cin >> x >> y >> v;
        g[x][y] = min(g[x][y], v);
    }
    dijkstra(1);
    if(vis[n]) cout << sd[n];
    else cout << "-1";
    cout << endl;
    PrintPath(1, 2);
    return 0;
}
