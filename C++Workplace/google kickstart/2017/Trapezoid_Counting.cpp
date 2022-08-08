
//
// Created by trudbot on 2022/8/1.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<pair<ll, ll>> vp;
const ll N = 5010;
ll pref[N];

vp translate(ll n)
{
    map<ll, ll> num;
    ll x;
    while(n --) {
        cin >> x;
        num[x]++;
    }
    vp ans = {{0, 0}};
    for(auto p : num) ans.push_back(p);
    return ans;
}

inline ll C(ll n, ll m)
{
    ll ans = 1;
    for(ll i=1; i<=m; i++) ans *= n, n--;
    for(ll i=2; i<=m; i++) ans /= i;
    return ans;
}

ll find(vp &data, ll tar, ll l)
{
    ll r = data.size()-1;
    while(l <= r)
    {
        ll mid = (l+r) >> 1;
        if(data[mid].first < tar) l = mid + 1;
        else r = mid-1;
    }
    return r;
}

int main() {
    ll T; cin >> T;
    ll n, ans;
    for(ll t=1; t<=T; t++)
    {
        cin >> n;
        vp data = translate(n);
        for(ll i=1; i<=n; i++) pref[i] = data[i].second + pref[i-1];
        ans = 0, n = (ll)data.size()-1;
        for(ll i=1; i<=n; i++)
        {
            if(data[i].second < 3) continue;
            ll x = data[i].first, y = data[i].second;
//            ll r = i;
//            while(r+1 <= n && data[r+1].first < 3*x) r++;
            ll r = find(data, 3*x, i);
            ans += (pref[r] - y) * C(y, 3);
        }

        for(ll i=1; i<=n; i++)
        {
            if(data[i].second < 2) continue;
            for(ll j=1; j<=n; j++)
            {
                if(i == j) continue;
                ll upper = (ll)data[j].first + 2 * (ll)data[i].first;
//                ll k = j;
//                while(k+1 <= n && data[k+1].first < upper) k++;
                ll k = find(data, upper, j);
                ll num = pref[k] - pref[j];
                if(i > j) num -= data[i].second;
                ans += num * C(data[i].second, 2) * data[j].second;
            }
        }

        printf("Case #%lld: %lld\n", t, ans);
    }

    return 0;
}