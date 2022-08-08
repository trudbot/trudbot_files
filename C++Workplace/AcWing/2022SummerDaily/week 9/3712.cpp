
//
// Created by trudbot on 2022/8/5.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e5 + 10;
vector<vector<pair<int, int>>> g;
int n, y;

vector<int> minCost;

int dfs(int v, int last, int m)
{
    minCost[v] = m;
    for(auto &i : g[v])
    {
        if(i.first == last) continue;
        dfs(i.first, v, min(m, i.second));
    }
}

int main() {
    int T; cin >> T;
    while( T-- )
    {
        cin >> n >> y;
        g.resize(n);
        minCost.resize(n);

        for(int i=1; i<n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        dfs(0, -1, 1e9);
        sort(minCost.begin(), minCost.end());

        if(n == y) cout << 0 << endl;
        else cout << minCost[n-y-1] + 1 << endl;

        g.clear();
    }

    return 0;
}