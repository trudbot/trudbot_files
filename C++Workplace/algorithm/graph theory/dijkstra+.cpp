//
// Created by trudbot on 2022/7/7.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 15001
int n, m;
vector<pii> g[N]; //pii{dest, weight}
int dist[N];
bool vis[N];
void dijkstra(int bg)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<> > pq;
    pq.push({0, bg});
    int t;
    while (!pq.empty())
    {
        t = pq.top().second;
        pq.pop();
        for(auto i : g[t])
        {
            if(dist[i.first] > dist[t]+)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    return 0;
}
