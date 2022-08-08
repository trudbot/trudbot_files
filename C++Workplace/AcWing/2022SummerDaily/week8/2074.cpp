
//
// Created by trudbot on 2022/7/25.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 2* 1e5 + 10;
int a[N];

int main() {

    int T, n, k;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> n >> k;
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);

        int ans = 0;
        for(int i=1; i<=n-k+1; i++)
        {
            if(a[i] != k) continue;
            int j;
            for(j=1; j<k; j++)
            {
                if (a[i + j] == k - j) continue;
                else break;
            }
            if(j == k) ans++;
            i += j;//移动到j停止的位置
            i--;//抵消i++
        }
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}