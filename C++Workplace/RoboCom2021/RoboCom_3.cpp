//
// Created by trudbot on 2022/7/8.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;
#define N 1010
int n, m;
int g[N][N];
int h[N], we[N], wv[N], e[N], ne[N], idx;
int dist[N];
int value[N];
bool vis[N];
int path[N];

void add(int x, int y, int z, int v)
{
    wv[idx] = v, we[idx] = z, e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

void floyd()
{
    for(int i=1; i<=n; i++)
        for(int x=1; x<=n; x++)
            for(int y=x+1; y<=n; y++)
                g[x][y] = g[y][x] = min(g[x][y], g[x][i]+g[i][y]);
}

int Find()
{
    int res, minE = INF;
    for(int i=1; i<=n; i++)
    {
        int maxE = 0;
        for(int j=1; j<=n; j++)
            if(g[i][j] > maxE && i!=j)
                maxE = g[i][j];
        if(maxE < minE)
        {
            res = i;
            minE = maxE;
        }
    }
    return res;
}

void dijkstra(int bg)
{
    memset(dist, 0x3f, sizeof dist);
    dist[bg] = 0;
    for(int i=1; i<=n; i++)
    {
        int t = -1;
        for(int j=1; j<=n; j++)
            if(!vis[j] && (t==-1 || dist[j] < dist[t]))
                t = j;
        for(int j=h[t]; j!=-1; j=ne[j])
        {
            int dest = e[j];
            if((dist[dest] > dist[t] + we[j]) ||
            (dist[dest] == dist[t] + we[j] && value[dest] < value[t] + wv[j]))
            {
                dist[dest] = dist[t] + we[j];
                value[dest] = value[t] + wv[j];
                path[dest] = t;
            }
        }
        vis[t] = true;
    }
}

void PrintPath(int bg, int tar)
{
    if(bg == tar)
    {
        cout << bg;
        return;
    }
    else PrintPath(bg, path[tar]);
    cout << "->" << tar;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(h, -1, sizeof h);
    memset(g, 0x3f, sizeof g);

    cin >> n >> m;
    int x, y, z, v;
    while (m--)
    {
        cin >> x >> y >> z >> v;
        g[x][y] = g[y][x] = z;
        add(x, y, z, v);
        add(y, x, z, v);
    }

    floyd();
    int bg = Find();
    cout << bg << endl;
    dijkstra(bg);
    int k; cin >> k;
    int tar;
    while(k--)
    {
        cin >> tar;
        PrintPath(bg, tar);
        cout << endl;
        cout << dist[tar] << " " << value[tar] << endl;
    }
    return 0;
}
