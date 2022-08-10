
//
// Created by trudbot on 2022/8/9.
//

#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ll n, k, s, T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> n >> k >> s;
        ll ans = min(k + k - s + n - s, n + k);
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}