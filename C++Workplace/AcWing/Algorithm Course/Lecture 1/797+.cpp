
//
// Created by trudbot on 2022/7/18.
//

#include <bits/stdc++.h>
using namespace std;
#define N 100010
int diff[N];

void insert(int l, int r, int c)
{
    diff[l] += c;
    diff[r+1] -= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        int t; cin >> t;
        insert(i, i, t);
    }
    while(m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for(int i=1; i<=n; i++)
    {
        diff[i] += diff[i-1];
        cout << diff[i] << ' ';
    }
    return 0;
}