//
// Created by trudbot on 2022/6/27.
//

#include <bits/stdc++.h>

using namespace std;

int dfs(int n, int m)
{
    if(n <= 1 || m == 1)
        return 1;
    if(n >= m)
        return dfs(n-m, m) + dfs(n, m-1);
    if(n < m)
        return dfs(n, n);
}

int main() {
    int n, m;
    while(cin >> n >> m)
        cout << dfs(n, m) << endl;
    return 0;
}

