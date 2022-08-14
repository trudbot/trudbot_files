
//
// Created by trudbot on 2022/8/14.
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
#define dwn(i, b, a) for(int (i)=b-1; (i)>=a; i--)
#define each(a, x) for(auto &(a) : (x))
#define sz(x) (int)(x).size()
#define mm(a, v) memset(a, v, sizeof a)
#define x first
#define y second
#define ins insert
#define pb push_back
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1010;
ll g[N][N], n;

ll get(int r, int c) {
    ll mx = 0;
    while(r <= n && c <= n) {
        mx += g[r][c];
        r++, c++;
    }
    return mx;
}

int main() {
    int T; cin >> T;
    rep(t, 1, T+1) {
        cin >> n;
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                cin >> g[i][j];
            }
        }

        ll mx = 0;
        rep(i, 1, n+1) {
            mx = max(mx, get(1, i));
        }
        rep(i, 2, n+1) {
            mx = max(mx, get(i, 1));
        }

        printf("Case #%d: %lld\n", t, mx);
    }
    return 0;
}