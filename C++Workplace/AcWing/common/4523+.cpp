
//
// Created by trudbot on 2022/7/16.
//

#include <bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define ll long long

vi operate(vi &arr, ll len)
{
    vi pref(len+2), suf(len+2), dp(len+2);
    for(int i=0; i<len; i++)
    {
        pref[i+1] = arr[i] + pref[i];
        suf[i+1] = arr[len-i-1] + suf[i];
    }

    for(int i=1; i<=len; i++)
        for(int j=0; j<=i; j++)
            dp[i] = max(dp[i], pref[j] + suf[i-j]);
    return dp;
}

ll Solution()
{
    ll n, m, k;
    cin >> n; vi A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    cin >> m; vi B(m);
    for(int i=0; i<m; i++) cin >> B[i];
    cin >> k;
    vi dpA = operate(A, n);
    vi dpB = operate(B, m);
    cout << dpA[n] << endl;
    ll res = 0;
    for(int i=1; i<=k; i++)
        if(i <= n && k-i <= m)
            res = max(res, dpA[i]+dpB[k-i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
        cout << "Case #" << i << ": " << Solution() << endl;
    return 0;
}