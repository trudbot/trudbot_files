//
// Created by trudbot on 2022/7/7.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 100010

int n, m;
vector<int> g[N];
int level[N];

void bfs()
{
    for(int i=1; i<=n; i++) level[i] = -1;
    queue<int> que;
    que.push(1);
    level[1] = 0;
    while (!que.empty())
    {
        int curr = que.front();
        que.pop();
        for(int i : g[curr])
            if(level[i] == -1)
            {
                que.push(i);
                level[i] = level[curr] + 1;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
    bfs();
    cout << level[n];
    return 0;
}
