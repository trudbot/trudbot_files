//
// Created by trudbot on 2022/7/7.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;

int n;
int seq[7];
int vis[10];

void dfs(int cnt)
{
    if(cnt == n)
    {
        for(int i=0; i<n; i++) cout << seq[i] << " ";
        cout << endl;
        return;
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
        {
            seq[cnt] = i;
            vis[i] = true;
            dfs(cnt+1);
            vis[i] = false;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    dfs(0);
    return 0;
}
