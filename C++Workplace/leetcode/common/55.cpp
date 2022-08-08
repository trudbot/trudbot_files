
//
// Created by trudbot on 2022/7/25.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool canJump(vector<int>& nums) {
        int maxL = 0, l = 0, r = nums.size()-1;
        while(l <= maxL)
        {
            maxL = max(maxL, l + nums[l]);
            if(maxL >= r) return true;
            l++;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vi = {2, 3, 1, 1, 4};
    cout << Solution::canJump(vi);
    return 0;
}