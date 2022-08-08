
//
// Created by trudbot on 2022/7/18.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
int diff[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    diff[x1][y1] += c;
    diff[x2+1][y1] -= c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y2+1] += c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;

    int x1, y1, x2, y2, c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> c;
            insert(i, j, i, j, c);
        }
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}