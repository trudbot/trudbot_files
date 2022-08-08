//
// Created by trudbot on 2022/7/6.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 1010
int n, m;
int g[N][N];
bool visited[N];

void dfs(int v)
{
    if(visited[v]) return;
    visited[v] = true;
    for(int i=1; i<=n; i++)
        if(g[v][i] != 0 && !visited[i]) dfs(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> n >> m) {
        memset(g, 0, sizeof g);
        memset(visited, false, sizeof visited);
        int x, y;
        while (m--) {
            cin >> x >> y;
            g[x][y] = g[y][x] = 1;
        }

        dfs(1);
        int i;
        for (i = 1; i <= n; i++)
            if (!visited[i]) {
                break;
            }
        if(i <= n) cout << "No" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
