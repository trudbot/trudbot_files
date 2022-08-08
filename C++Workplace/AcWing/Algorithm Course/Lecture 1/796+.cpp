
//
// Created by trudbot on 2022/7/17.
//

#include <bits/stdc++.h>
using namespace std;
#define N 1010
int pref[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            int t; cin >> t;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + t;
        }
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1] << endl;
    }
    return 0;
}