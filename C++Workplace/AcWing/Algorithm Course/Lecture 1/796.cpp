
//
// Created by trudbot on 2022/7/17.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
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
            int t;
            cin >> t;
            pref[i][j] = pref[i][j-1] + t;
        }
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int i=x1; i<=x2; i++)
            sum += pref[i][y2] - pref[i][y1-1];
        cout << sum << endl;
    }

    return 0;
}