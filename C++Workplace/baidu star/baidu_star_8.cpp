
//
// Created by trudbot on 2022/8/27.
//

//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
__attribute__((unused)) int io_ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}();

#define rep(i, a, b) for(int (i)=a; (i)<(b); (i)++)
typedef pair<int, int> pii;
const int N = 10010;
int n, m;
int dist[N][N], vis[N][N], h[N][N];

int main() {
    cin >> n >> m;
    queue<pii> que;
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            vis[i][j] = false;
            dist[i][j] = -1;
            cin >> h[i][j];
            if(h[i][j] == 0) {
                que.push({i, j});
                dist[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    int x, y, d;
    auto add = [&] (int r, int c) -> void {
        if(r < 1 || r > n || c < 1 || c > m || vis[r][c] || h[r][c] < h[x][y]) {
            return;
        }
        dist[r][c] = d;
        vis[r][c] = true;
        que.push({r, c});
    };

    while(!que.empty()) {
        pii p = que.front(); que.pop();
        x = p.first, y = p.second;
        d = dist[x][y] + 1;
        add(x-1, y), add(x+1, y), add(x, y-1), add(x, y+1);
    }

    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}