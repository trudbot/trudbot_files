//
// Created by trudbot on 2022/7/9.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 50010;
int p[N], cnt;

int Find(int x)
{
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, d, x, y, res = 0;
    map<int, int> chain;
    cin >> n >> k;
    for(int i=1; i<=n; i++) p[i] = i;
    while (k--)
    {
        cin >> d >> x >> y;
        if (d == 1)
        {

        }
    }
    return 0;
}
