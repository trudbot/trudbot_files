
//
// Created by trudbot on 2022/7/16.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m;
    vector<int> nums;
    cin >> t;
    for(int j=1; j<=t; j++)
    {
        double res = 0;
        cin >> n >> m;
        nums.resize(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        int i = n-m+1;
        if(i % 2 == 0) res += (nums[i/2] + nums[i/2-1]) / 2.0;
        else res += nums[i/2];
        for(i; i<n; i++)
            res += nums[i];
        printf("Case #%d: %.1lf\n", j, res);
    }
    return 0;
}