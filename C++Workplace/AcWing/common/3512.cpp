
//
// Created by trudbot on 2022/7/20.
//

#include <bits/stdc++.h>
#define N 510
using namespace std;
int g[N][N];
int t[N][N];
int n;

int Solution()
{
    int ans = 0;
    for(int d=1; d<n-1; d++)
    {
        memcpy(t, g, sizeof t);
        for(int x=d+1; x<=n; x++)
            for(int i=d+1; i<=n; i++)
                for(int j=d+1; j<=n; j++)
                    t[i][j] = min(t[i][j], t[i][x]+t[x][j]);
        for(int i=d+1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                ans += t[i][j];
    }
    return ans * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> g[i][j];
    cout << Solution() << endl;
    return 0;
}