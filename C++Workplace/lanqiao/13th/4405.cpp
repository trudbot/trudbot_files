
//
// Created by trudbot on 2022/8/13.
//

//pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, from, to) for(int (i)=from; (i)<(to); (i)++)
#define each(a, x) for(auto &(a) : (x))
#define sz(x) (int)(x).size()
#define x first
#define y second
#define ins insert
#define pb push_back
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set

const int N = 510;
int sum[N][N], n, m, k;

int get(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

int main() {
    FASTIO;
    cin >> n >> m >> k;

    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            cin >> sum[i][j];
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int ans = 0;
    rep(l, 1, m + 1) {
        rep(r, l, m + 1) {
            int top = 1;
            rep(b, 1, n + 1) {
                while (top <= b && get(top, l, b, r) > k) top++;
                if (top <= b) {
                    ans += b - top + 1;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}