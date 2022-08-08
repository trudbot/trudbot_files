//
// Created by trudbot on 2022/7/7.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define Inf 0x3f3f3f3f
#define N 510
int n, m;
int g[N][N];
int sd[N];
bool vis[N];
int path[N];

void dijkstra(int bg)
{
    memset(sd, 0x3f, sizeof sd);
    sd[bg] = 0;
    int mi;
    for(int i=1; i<=n; i++)
    {
        mi = -1;
        for(int j=1; j<=n; j++)
            if(!vis[j] &&(mi == -1 || sd[j] < sd[mi]))
                mi = j;
        for(int j=1; j<=n; j++)
            if(sd[j] > sd[mi]+g[mi][j])
            {
                sd[j] = sd[mi]+g[mi][j];
                path[j] = mi;
            }
        vis[mi] = true;
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
    memset(g, 0x3f, sizeof g);
    int x, y, v;
    while(m--)
    {
        cin >> x >> y >> v;
        g[x][y] = min(g[x][y], v);
    }
    dijkstra(1);
    cout << sd[n] << endl;
    PrintPath(1, 3);
    return 0;
}
