
//
// Created by trudbot on 2022/8/7.
//

#include <bits/stdc++.h>

#define pb push_back;
#define uset unordered_set
#define umap unordered_map
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define rep(from, to) for(int i=from; i<to; i++)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
    FASTIO
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        cout << "Case #" << t << ": ";
        string s; int n; cin >> n >> s;
        vi res(n);
        res[0] = 1;
        rep(1, n)
        {
            res[i] = 1;
            if(s[i] > s[i-1]) res[i] += res[i-1];
        }

        rep(0, n) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}