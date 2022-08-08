//
// Created by trudbot on 2022/7/2.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;

void MergeSort(int a[], int l, int r, int temp[])
{
    if(l >= r) return;
    int mid = (l+r)>>1;
    MergeSort(a, l, mid, temp), MergeSort(a, mid+1, r, temp);
    int i = l, j = mid+1, k = 0;
    while(i <= mid && j <= r)
    {
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(i=l, k=0; i<=r; i++, k++)
        a[i] = temp[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int arr[n], temp[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    MergeSort(arr, 0, n-1, temp);
    for(int i=0; i<n; i++) cout << arr[i] << " ";

    return 0;
}
