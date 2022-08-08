
//
// Created by trudbot on 2022/7/20.
//

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int N = 2010;
int n;
bool g[N][N], st[N];

vi dfs(int v)
{
    vi Max = {0};
    st[v] = true;
    for(int i=1; i<=n; i++)
    {
        if(!st[i] && g[v][i])
        {
            vi t = dfs(i);
            if(t[0] > Max[0])
                Max = t;
        }
    }
    st[v] = false;
    vi ans = {Max[0]+1};
    ans.push_back(v);
    for(int i=1; i<Max.size(); i++)
        ans.push_back(Max[i]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            int t; cin >> t;
            if(t == 1) g[j][i] = true;
            else g[i][j] = true;
        }
    }

    for(int i=1; i<=n; i++)
    {
        vi ans = dfs(i);
        for(int e : ans) cout << e << " ";
        cout << endl;
    }
    return 0;
}