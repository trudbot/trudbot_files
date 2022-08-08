//
// Created by trudbot on 2022/7/2.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
int a[100001], temp[100001];

ll Count(ll l, ll r)
{
    if(l >= r) return 0;
    ll num = 0, mid = (l+r)>>1;
    num += Count(l, mid) + Count(mid+1, r);
    ll i = l, j = mid+1, k = 0;
    while(i<=mid && j<=r)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            num += mid-i+1;
        }
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(i=l, k=0; i<=r; i++, k++) a[i] = temp[k];
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cout << Count(0, n-1);
    return 0;
}
