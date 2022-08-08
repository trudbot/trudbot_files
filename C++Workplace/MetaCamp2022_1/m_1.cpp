
//
// Created by trudbot on 2022/8/2.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
vector<string> r1, r2;
unordered_set<string> st;
set<string> rise;
int k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k;
    int n; cin >> n;
    while(n --) {
        string x;
        cin >> x;
        r1.push_back(x);
    }

    int m; cin >> m;
    while(m --) {
        string x; cin >> x;
        r2.push_back(x);
    }

    int q; cin >> q;
    while(q--) {
        string x;
        cin >> x;
        st.insert(x);
    }

    int cnt = 0;
    for(auto &x : r1) {
        if(st.count(x)) {
            cnt++;
            rise.insert(x);
        }
        if(cnt == k) {
            break;
        }
    }

    cnt = 0;
    for(auto &x : r2) {
        if(st.count(x) && !rise.count(x)) {
            cnt++;
            rise.insert(x);
        }
        if(cnt == k) {
            break;
        }
    }

    cout << rise.size() << endl;
    for(auto x : rise) {
        cout << x << endl;
    }
    return 0;
}