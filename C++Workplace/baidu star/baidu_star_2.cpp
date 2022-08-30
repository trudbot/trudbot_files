
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
    priority_queue<pii, vector<pii>, greater<>> dat;
    int n, k; cin >> n >> k;
    rep(i, 1, n+1) {
        int a; cin >> a;
        dat.push({a, i});
    }

    ll ans = 0;
    rep(i, k+1, k+n+1) {
        vector<pii> tmp;
        while(dat.top().y < i) {
            tmp.push_back(dat.top());
            dat.pop();
        }
        pii curr = dat.top(); dat.pop();
        cout << curr.x << " " << curr.y << endl;
        ans += curr.x * (i*i - curr.y * curr.y);
        each(a, tmp) {
            dat.push(a);
        }
    }


    cout << ans << endl;
    return 0;
}