
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

const int N = 110;
int g[N][N], n;

int main() {
    int T; cin >> T;
    rep(t, 1, T+1) {
        cin >> n;
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                cin >> g[i][j];
            }
        }
        vector<pii> ans;
        rep(i, 1, n+1) {
            rep(j, i+1, n+1) {
                bool flag = true;
                rep(x, 1, n+1) {
                    if(x == i || x == j) {
                        continue;
                    } else if(g[i][j] == g[i][x] + g[x][j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans.emplace_back(i, j);
                }
            }
        }
        cout << ans.size() << endl;
        each(a, ans) {
            cout << a.x << " " << a.y << endl;
        }
    }
    return 0;
}