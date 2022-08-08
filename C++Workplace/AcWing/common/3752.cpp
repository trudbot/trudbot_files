
//
// Created by trudbot on 2022/8/6.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;

ll modpow(ll x, ll e)
{
    if (e == 0) return 1;
    ll a = modpow(x, e >> 1);
    a = a * a % mod;
    if (e & 1) a = a * x % mod;
    return a;
}

int main() {

    ll n, k, T;
    string s;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> n >> k >> s;
        ll ans = 0, mid = (n-1) / 2;

        for(ll i = 0; i<=mid; i++)
            ans += (s[i] - 'a') * modpow(k, mid-i);

        bool flag = false;
        ll i, j;
        if(n%2 == 0) i = mid, j = mid + 1;
        else i = mid-1, j = mid+1;
        while(i >= 0)
        {
            if(s[i] != s[j])
            {
                flag = s[i] < s[j];
                break;
            }
            i--, j++;
        }
        if(flag) ans++;

        printf("Case #%d: %lld\n", t, ans % mod);
    }
    return 0;
}