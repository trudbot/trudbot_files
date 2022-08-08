//
// Created by trudbot on 2022/7/6.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define N 210
#define Inf 1e9
using namespace std;
int n, m, k;
int g[N][N];

void floyd()
{
    for(int i=1; i<=n; i++)
        for(int x=1; x<=n; x++)
            for(int y=1; y<=n; y++)
                g[x][y] = min(g[x][y], g[x][i]+g[i][y]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    int x, y, z;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i == j) g[i][j] = 0;//解决自环
            else g[i][j] = Inf;

    while(m--)
    {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);//去除重边
    }
    floyd();
    while(k--)
    {
        cin >> x >> y;
        if(g[x][y] > Inf/2) cout << "impossible\n";//有负边， 所以不可达路径可能加上负数而变小
        else cout << g[x][y] << endl;
    }
    return 0;
}
