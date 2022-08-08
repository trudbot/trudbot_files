
//
// Created by trudbot on 2022/7/18.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N], n;
int ans;

void Solution() {
    unordered_map<int, bool> m;
    int i, j;
    for(i = 0, j = 0; i<n; i++)
    {
        while(m[a[i]]) m[a[j++]] = false;
        m[a[i]] = true;
        ans = max(ans, i-j+1);
    }
    ans = max(ans, i-j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    Solution();
    cout << ans;
    return 0;
}