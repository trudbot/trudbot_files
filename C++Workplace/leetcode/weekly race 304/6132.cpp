
//
// Created by trudbot on 2022/7/31.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums[0] == 0 ? nums.size()-1 : nums.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v {1,2,3,5};
    Solution s;
    cout << s.minimumOperations(v);
    return 0;
}