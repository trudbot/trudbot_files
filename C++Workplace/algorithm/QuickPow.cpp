//
// Created by trudbot on 2022/7/5.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
#define MOD 233333

ll QuickPow1(ll x, ll n)
{
    if(n == 0) return 1;
    ll res = QuickPow1(x, n>>1);
    res = res * res % MOD;
    if(n & 1) res = res * x % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x, n;
    cin >> x >> n;
    cout << QuickPow1(x, n);
    return 0;
}
