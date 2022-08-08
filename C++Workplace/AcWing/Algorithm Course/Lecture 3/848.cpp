//
// Created by trudbot on 2022/7/6.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 100010
int n, m;
vector<int> g[N];
int ind[N];
int len = 0;
int topSeq[N];

bool topSort()
{
    queue<int> que;
    for(int i=1; i<=n; i++)
        if(ind[i] == 0)
            que.push(i);
    int curr;
    while (!que.empty())
    {
        curr = que.front();
        que.pop();
        topSeq[len++] = curr;
        for(int i : g[curr])
            if(--ind[i] == 0)
                que.push(i);
    }
    return len == n;
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
        ind[y]++;
    }
    if(topSort())
    {
        for(int i=0; i<len; i++)
            cout << topSeq[i] << " ";
    }
    else cout << -1;
    return 0;
}
