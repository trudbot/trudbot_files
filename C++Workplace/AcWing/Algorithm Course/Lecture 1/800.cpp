
//
// Created by trudbot on 2022/7/19.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    for(int i = 0, j = m-1; i<n && j>=0; i++)
    {
        while(b[j] + a[i] > x) j--;
        if(b[j] + a[i] == x)
        {
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}