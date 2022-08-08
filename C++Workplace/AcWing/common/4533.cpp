
//
// Created by trudbot on 2022/7/20.
//

#include <bits/stdc++.h>
using namespace std;
#define N 230
int n;
bool g[N][N], st[N];
int ind[N];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int x, y;
    while(cin >> x >> y)
    {
        g[x][y] = g[y][x] = true;
        ind[x]++, ind[y]++;
    }
    return 0;
}