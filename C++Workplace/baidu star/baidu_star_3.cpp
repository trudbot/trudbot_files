
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
const int N = 1e5  + 10;
int a[N], n;

bool dfs(int i, stack<int> &g, stack<int> &l) {
    if(i == n+1) {
        return !(g.empty() || l.empty());
    }
    if(g.empty() || a[i] >= g.top()) {
        g.push(a[i]);
        if(dfs(i+1, g, l)) {
            return true;
        }
        g.pop();
    }
    if(l.empty() || a[i] <= l.top()) {
        l.push(a[i]);
        if(dfs(i+1, g, l)) {
            return true;
        }
        l.pop();
    }
    return false;
}

int main() {
    cin >> n;
    rep(i, 1, n+1) {
        cin >> a[i];
    }
    stack<int> g, l;
    cout << (dfs(1, g, l) ? "Yes" : "No") << endl;

    return 0;
}