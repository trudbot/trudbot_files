
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
        cout << "Case #" << t << ": ";
        int n, m; cin >> n;
        vi site(n), a, b;
        rep(i, 0, n) {
            cin >> m;
            site[i] = ((m % 2 > 0 ? m % 2 : m % 2 + 2) == 1);
            if(site[i]) {
                a.push_back(m);
            } else {
                b.push_back(m);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<>());
        int i = 0, j = 0;
        each(flag, site) {
            if(flag) {
                cout << a[i++] << " ";
            } else {
                cout << b[j++] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}