
//
// Created by trudbot on 2022/7/22.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int r[N], l[N], p[N], d[N];

int h[N], e[4*N], ne[4*N], idx;
int vis[N], res[4*N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int x, int depth)
{
    if(x == -1) return ;
    d[x] = depth;
    dfs(l[x], depth+1);
    dfs(r[x], depth+1);
}

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
    e[idx] = x, ne[idx] = h[y], h[y] = idx++;
}

void tarjan(int x)
{
    if(l[x] != -1) tarjan(l[x]), p[l[x]] = x;
    if(r[x] != -1) tarjan(r[x]), p[r[x]] = x;
    vis[x] = true;
    for(int i=h[x]; i!=-1; i=ne[i])
    {
        int y = e[i];
        if(vis[y]) res[i] = d[x] + d[y] - 2*d[find(y)];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            int s1, s2; cin >> s1 >> s2;
            l[i] = s1, r[i] = s2;
            h[i] = -1, p[i] = i;
        }

        for(int i=1; i<=m; i++)
        {
            int x, y;
            cin >> x >> y;
            add(x, y);
        }
        dfs(1, 1);
        tarjan(1);
        for(int i=0; i<2*m; i++)
            if(res[i] != 0)
                cout << res[i] << endl;
        memset(res, 0, sizeof res);
        memset(vis, false, sizeof vis);
        idx = 0;
    }

    return 0;
}