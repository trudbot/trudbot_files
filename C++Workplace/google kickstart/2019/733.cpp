
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

const int N = 1e5 + 10;
int cnt[N][26];

void getPref(string &s) {
    rep(i, 0, sz(s)) {
        rep(j, 0, 26) {
            cnt[i + 1][j] = 0;
            cnt[i + 1][j] += cnt[i][j];
        }
        cnt[i + 1][s[i] - 'A']++;
    }
}

bool judge(int l, int r) {
    int odd = 0;
    rep(i, 0, 26) {
        if ((cnt[r][i] - cnt[l - 1][i]) & 1) {
            odd++;
        }
    }
    return odd <= 1;
}

int main() {
    int T;
    cin >> T;
    int l, r, n, q;
    rep(t, 1, T + 1) {
        cin >> n >> q;
        string s;
        cin >> s;
        getPref(s);
        int ans = 0;
        rep(i, 0, q) {
            cin >> l >> r;
            if (judge(l, r)) {
                ans++;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}