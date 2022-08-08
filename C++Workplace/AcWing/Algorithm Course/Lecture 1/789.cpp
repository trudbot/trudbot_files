//
// Created by trudbot on 2022/7/3.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

int a[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];

    int l, r, k, mid;
    while(q--)
    {
        cin >> k;
        l = 0, r = n-1;
        while(l < r)
        {
            mid = (l+r)/2;
            if(a[mid] >= k) r = mid;
            else l = mid+1;
        }
        if(a[l] != k)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << " ";
        r = n-1;
        while(l < r)
        {
            mid = (l+r)/2+1;
            if(a[mid] <= k) l = mid;
            else r = mid-1;
        }
        cout << l << endl;
    }
    return 0;
}
