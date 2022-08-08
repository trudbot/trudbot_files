
//
// Created by trudbot on 2022/7/17.
//

#include <bits/stdc++.h>

using namespace std;
#define N 100010
int arr[N];
int pref[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + arr[i];

    int l, r;
    while(m--)
    {
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
    return 0;
}