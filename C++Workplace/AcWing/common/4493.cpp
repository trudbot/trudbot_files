//
// Created by trudbot on 2022/7/9.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 2*1e5 + 10;
int n, m;
int p[N], d[N];
int st[N];

int Find(int x)
{
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; i++) p[i] = i;
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        p[Find(u)] = Find(v);
        d[u]++, d[v]++;
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
        if(d[i] != 2)
            st[Find(i)] = true;

    for(int i=1; i<=n; i++)
        if(i == p[i] && !st[i])
            ans++;
    cout << ans << endl;
    return 0;
}
