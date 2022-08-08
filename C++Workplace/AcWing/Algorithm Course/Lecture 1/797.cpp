
//
// Created by trudbot on 2022/7/17.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
#define N 100010
int arr[N];
int diff[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
        diff[i] = arr[i]-arr[i-1];
    }

    while(m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c, diff[r+1] -= c;
    }

    for(int i=1; i<=n; i++)
    {
        arr[i] = arr[i-1] + diff[i];
        cout << arr[i] << " ";
    }
    return 0;
}