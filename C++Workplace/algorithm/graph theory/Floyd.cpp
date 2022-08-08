//
// Created by trudbot on 2022/7/5.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 1010

int Inf = 1e9;
int g[N][N];
int path[N][N];

void floyd(int n)
{
    int i, x, y;
    for(i=1; i<=n; i++)
        for(x=1; x<=n; x++)
            for(y=1; y<=n; y++)
                if(g[x][i]+g[i][y] < g[x][y])
                {
                    g[x][y] = g[x][i] + g[i][y];
                    path[x][y] = path[x][i];
                }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int c; cin >> c;
    int x, y, w;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i == j) g[i][j] = 0;
            else g[i][j] = Inf;
        }
    while(c--)
    {
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;
        path[x][y] = y;
        path[y][x] = x;
    }
    floyd(n);
    cout << g[1][4] << endl;
    int i=2;
    while(i != 4)
    {
        cout << i << " ";
        i = path[i][4];
    }
    cout << 4;
    return 0;
}

/*
4 3
1 2 1
2 3 2
3 4 3
*/
