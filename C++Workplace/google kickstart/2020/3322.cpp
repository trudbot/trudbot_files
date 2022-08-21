
//
// Created by trudbot on 2022/8/20.
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
#define each(a, x) for(auto &(a) : (x))
#define sz(x) (int)(x).size()
#define x first
#define y second
typedef pair<int, int> pii;

int main() {
    int T; cin >> T;
    rep(t, 1, T+1) {
        int n, k;
        vector<pii> vp;
        cin >> n >> k;
        vp.resize(n);
        rep(i, 0, n) {
            cin >> vp[i].x >> vp[i].y;
        }
        sort(vp.begin(), vp.end());
        int last = 0, ans = 0;

        each(p, vp) {
            p.x = max(p.x, last);
            if(p.x < p.y) {
                int cnt = (p.y - p.x - 1) / k + 1;
                ans += cnt;
                last = p.x + cnt * k;
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}