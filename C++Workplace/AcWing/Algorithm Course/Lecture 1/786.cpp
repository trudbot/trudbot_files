//
// Created by trudbot on 2022/7/2.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;

void qsort(int a[], int l, int r)
{
    if(l >= r) return;
    int i = l-1, j = r+1, p = a[(l+r)>>1];
    while(i < j)
    {
        do i++; while(a[i] < p);
        do j--; while(a[j] > p);
        if(i<j) swap(a[i], a[j]);
    }
    qsort(a, l, j), qsort(a, j+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k; cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    qsort(arr, 0, n-1);
    cout << arr[k-1];
    return 0;
}
