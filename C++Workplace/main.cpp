#include <bits/stdc++.h>
using namespace std;

int solve(int x, vector<int> &nums) {
    sort(nums.begin(), nums.end());
    if(nums[0] != 1) {
        return -1;
    }
    int ans = 0, mx = 0, i = 0;
    while(mx < x) {
        ans ++;
        while(i < nums.size() - 1 && nums[i + 1] <= mx + 1) {
            i++;
        }
        cout << mx << " " << nums[i] << endl;
        mx += nums[i];
    }
    return ans;
}

int main() {
    int x, n; cin >> x >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << solve(x, nums);
    return 0;
}