//
// Created by trudbot on 2022/7/2.
//归并排序记忆版

#include <bits/stdc++.h>

#define ll long long
#define N 100
using namespace std;

ll a[N], temp[N];

void MergeSort(ll l, ll r)
{
    if(l >= r) return;
    ll mid = (l+r)/2;
    MergeSort(l, mid), MergeSort(mid+1, r);

    ll i = l, j = mid+1, k = 0;
    while(i<=mid && j<=r)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(i=l, k=0; i<=r; i++, k++) a[i] = temp[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin>> a[i];
    MergeSort(0, n-1);
    for(int i=0; i<n; i++) cout << a[i] << " ";
    return 0;
}
