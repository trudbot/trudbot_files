//
// Created by trudbot on 2022/7/8.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define Inf 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool vis[N];

void add(int x, int y, int z)
{
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

void dijkstra(int bg)
{
    priority_queue<pii, vector<pii>, greater<>> heap;
    memset(dist, 0x3f, sizeof dist);
    dist[bg] = 0;
    heap.push({0, bg});

    int cv;
    while(!heap.empty())
    {
        cv = heap.top().second;
        heap.pop();
        if(vis[cv]) continue;
        for(int i=h[cv]; i!=-1; i=ne[i])
        {
            int dest = e[i];
            if(dist[dest] > dist[cv] + w[i])
            {
                dist[dest] = dist[cv] + w[i];
                heap.push({dist[dest], dest});
            }
        }
        vis[cv] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    memset(h, -1, sizeof h);
    int x, y, z;
    while(m--)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    dijkstra(1);
    cout << (dist[n] == Inf ? -1 : dist[n]);
    return 0;
}
