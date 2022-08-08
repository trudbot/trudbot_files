
//
// Created by trudbot on 2022/7/16.
//TLE

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
#define N 6000
int A[N], B[N];
int la, ra, lb, rb;

ll dfs(int cnt)
{
    if(cnt == 0) return 0;
    ll Max = 0;
    if(la <= ra)
    {
        Max = max(Max, A[la++] + dfs(cnt-1));
        la--;
        Max = max(Max, A[ra--] + dfs(cnt-1));
        ra++;
    }
    if(lb <= rb)
    {
        Max = max(Max, B[lb++] + dfs(cnt-1));
        lb--;
        Max = max(Max, B[rb--] + dfs(cnt-1));
        rb++;
    }
    return Max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n, m, k;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        cin >> n;
        for(int j=0; j<n; j++) cin >> A[j];
        cin >> m;
        for(int j=0; j<m; j++) cin >> B[j];
        la = lb = 0, ra = n-1, rb = m-1;
        cin >> k;
        printf("Case #%d: %d\n", T, dfs(k));
    }
    return 0;
}