//
// Created by trudbot on 2022/7/2.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define N 10001

int p[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=2; i<=n; i++) cin >> p[i];
    for(int i=1; i<=n; i++) cin >> c[i];

    int res = 1;//结点的目标颜色大于0， 所以根结点一定要染一次
    for(int i=2; i<=n; i++)
        if(c[i] != c[p[i]])//只要结点的颜色与其父节点颜色不同， 就需要染一次
            res++;
    cout << res;
    return 0;
}
