//
// Created by trudbot on 2022/7/9.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans;

void Solution(ll x)
{
    if(x % 2 == 0)
    {
        ans = x/2;
        return;
    }
    int i;
    for(i=2; i<=x/i; i++)
    {
        if(x % i == 0)
        {
            x -= i;
            ans+=1;
            break;
        }
    }
    if (x % 2 == 1) ans = 1;
    else ans += x/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    Solution(n);
    cout << ans;
    return 0;
}


