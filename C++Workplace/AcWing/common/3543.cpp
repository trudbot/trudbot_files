
//
// Created by trudbot on 2022/7/31.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        unordered_map<int, int> cnt;
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            cnt[nums[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                int x = nums[i] + nums[j];
                if(cnt.count(x)) {
                    ans += cnt[x];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}