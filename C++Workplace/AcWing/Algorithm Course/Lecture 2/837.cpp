//
// Created by trudbot on 2022/7/9.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N =  1e5 + 10;

int p[N], w[N];
int n, m;

int Find(int x)
{
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; i++) p[i] = i, w[i] = 1;
    string order;
    int a, b;
    while (m--)
    {
        cin >> order;
        if (order == "C")
        {
            cin >> a >> b;
            a = Find(a), b = Find(b);
            if(a == b) continue;
            p[a] = b;
            w[b] += w[a];
        }
        else if(order == "Q1")
        {
            cin >> a >> b;
            cout << (Find(a) == Find(b) ? "Yes" : "No") << endl;
        }
        else
        {
            cin >> a;
            cout << w[Find(a)] << endl;
        }
    }
    return 0;
}
