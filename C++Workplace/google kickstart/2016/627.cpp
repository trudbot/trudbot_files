
//
// Created by trudbot on 2022/8/21.
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
typedef long long ll;


int main() {
    int T; cin >> T;
    rep(t, 1, T+1) {
        cout << "Case #" << t << ": ";
        string s; cin >> s;
        ll total = 0, l, r;
        each(ch, s) {
            total += ch == 'B';
        }
        cin >> l >> r;
        ll ans = (r -l + 1) / sz(s) * total;
        ll len = (r - l + 1) % sz(s);
        l %= sz(s);
        if(l == 0) {
            l = sz(s);
        }

        s.append(s), s.insert(0, "R");
        rep(i, l, l + len) {
            ans += s[i] == 'B';
        }
        cout << ans << endl;
    }
    return 0;
}