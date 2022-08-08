//
// Created by trudbot on 2022/7/9.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;

int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) p[i] = i;
    char order;
    int a, b;

    while(m--)
    {
        cin >> order >> a >> b;
        if (order == 'M') p[find(a)] = find(b);
        else if(find(a) == find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
