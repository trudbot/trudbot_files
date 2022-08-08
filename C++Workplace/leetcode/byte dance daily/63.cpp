
//
// Created by trudbot on 2022/8/1.
//爆搜， 超时， 未过

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n, m;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        g = obstacleGrid;
        n = g.size()-1, m = g[0].size()-1;
        if(g[n][m] == 1 || g[0][0] == 1) return 0;
        return dfs(0, 0);
    }

    int dfs(int x, int y) {
        if(x == n && y == m) {
            return 1;
        }
        int res = 0;
        if(x < n && g[x+1][y] != 1) {
            res += dfs(x+1, y);
        }
        if(y < m && g[x][y+1] != 1) {
            res += dfs(x, y+1);
        }
        return res;
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