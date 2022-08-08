//
// Created by trudbot on 2022/7/5.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
int main()
{
    ll x, n, MOD = 233333, r = 1;
    cin >> x >> n;
    while(n)
    {
        if(n & 1) r = (r * x) % MOD;
        n  = n >> 1;
        x = (x * x) % MOD;
    }
    cout << r%MOD;
    return 0;
}

#include <bits/stdc++.h>

#define ll long long
using namespace std;
int MOD = 233333;
ll f(ll a,ll b)
{
    if(!b) return 1;
    ll t=f(a,b>>1);
    t=t*t%MOD;
    if(b&1) t=t*a%MOD;
    return t%MOD;
}

int main()
{
    ll x, n, MOD = 233333, r = 1;
    cin >> x >> n;
    // while(n)
    // {
    //     if(n & 1) r = (r * x) % MOD;
    //     n  = n >> 1;
    //     x = (x * x) % MOD;
    // }
    // cout << r%MOD;
    cout << f(x, n);
    return 0;
}
