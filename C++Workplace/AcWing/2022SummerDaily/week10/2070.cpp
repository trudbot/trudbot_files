
//
// Created by trudbot on 2022/8/10.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    int a[110], n;
    for(int t=1; t<=T; t++)
    {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        int ans = 0;
        for(int i=2; i<n; i++)
            if(a[i] > a[i-1] && a[i] > a[i+1])
                ans++;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}