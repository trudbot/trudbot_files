
//
// Created by trudbot on 2022/8/11.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int pre[n], suffix[n];
        pre[0] = nums[0], suffix[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
            pre[i] = min(nums[i], pre[i-1]);
        for(int i=n-2; i>=0; i--)
            suffix[i] = max(suffix[i+1], nums[i]);

        bool flag = false;
        for(int i=1; i<=n-2; i++)
            if(nums[i] > pre[i-1] && nums[i] < suffix[i+1])
            {
                flag = true;
                break;
            }
        return flag;
    }
};

int main() {

    return 0;
}