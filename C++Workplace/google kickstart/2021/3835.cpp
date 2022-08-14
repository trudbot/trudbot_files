
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

ll dat[4][4];

ll get() {
    umap<ll, ll> cnt;
    auto add = [&cnt](ll a, ll b) -> void {
        if((a+b) % 2 == 0) {
            cnt[(a+b)/2]++;
        }
    };

    add(dat[1][1], dat[3][3]);
    add(dat[1][2], dat[3][2]);
    add(dat[2][1], dat[2][3]);
    add(dat[3][1], dat[1][3]);

    ll mx = 0;
    each(p, cnt) {
        if(p.y > mx) {
            mx = p.y;
        }
    }

    if(dat[1][2] * 2 == dat[1][1] + dat[1][3]) mx++;
    if(dat[2][1] * 2 == dat[1][1] + dat[3][1]) mx++;
    if(dat[3][2] * 2 == dat[3][1] + dat[3][3]) mx++;
    if(dat[2][3] * 2 == dat[1][3] + dat[3][3]) mx++;

    return mx;
}

int main() {
    int T; cin >> T;
    rep(t, 1, T+1) {
        rep(i, 1, 4) {
            cin >> dat[1][i];
        }
        cin >> dat[2][1] >> dat[2][3];
        rep(i, 1, 4) {
            cin >> dat[3][i];
        }
        printf("Case #%d: %lld\n", t, get());

    }
    return 0;
}