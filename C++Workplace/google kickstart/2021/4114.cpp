
//
// Created by trudbot on 2022/8/12.
//

#include <bits/stdc++.h>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main() {
    FASTIO;
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        int n; cin >> n;
        string s; cin >> s;
        s.insert(0, "0");
        ll left[n+1], right[n+2];
        left[0] = -1e6, right[n+1] = 1e6;
        for(int i=1; i<=n; i++)
            left[i] = s[i] == '1' ? i : left[i-1];
        for(int i=n; i>=1; i--)
            right[i] = s[i] == '1' ? i : right[i+1];

        ll ans = 0;
        for(int i=1; i<=n; i++)
            ans += min(i - left[i], right[i] - i);
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}