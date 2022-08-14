
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
#define dwn(i, b, a) for(int (i)=(b)-1; (i)>=(a); (i)--)
#define each(a, x) for(auto &(a) : (x))
#define sz(x) (int)(x).size()
#define mm(a, v) memset(a, v, sizeof (a))
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


int main() {
    int T; cin >> T;
    rep(t, 1, T+1) {
        ll g; cin >> g;
        ll d, ans = 0;

        for(d = 1; d*(d+1)/2 <= g; d++) {
            ll a = 2*g + d - d*d;
            if(a % (2*d) == 0) {
                ans++;
            }
        }

        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}