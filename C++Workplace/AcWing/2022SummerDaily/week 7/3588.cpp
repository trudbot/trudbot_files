
//
// Created by trudbot on 2022/7/20.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0)
    {
        int ans = 0;
        for(int i=n; i>=n-m+1; i--)
        {
            int x = i;
//            while((x&1) == 0)
//            {
//                ans++;
//                x >>= 1;
//            }
            ans += (int)log2(x & (-x));
        }
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}