
//
// Created by trudbot on 2022/8/1.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        int g[n+1][m+1];
        memset(g, 0, sizeof g);
        g[1][1] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(nums[i-1][j-1] == 1) {
                    g[i][j] = 0;
                } else {
                    g[i][j] += g[i-1][j] + g[i][j-1];
                }
            }
        }
        return g[n][m];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> nums = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution solution;
    cout << solution.uniquePathsWithObstacles(nums);
    return 0;
}