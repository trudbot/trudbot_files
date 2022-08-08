
//
// Created by trudbot on 2022/8/1.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> d;
int n, m;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        n = (int) obstacleGrid.size(), m = (int) obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0;
        d = vector<vector<int>>(n, vector<int>(m, -1));
        return dfs(0, 0, obstacleGrid);
    }

    int dfs(int r, int c, vector<vector<int>> &g) {
        if (r == n - 1 && c == m - 1) {
            return 1;
        }
        if (d[r][c] == -1) {
            d[r][c] = 0;
            if (r < n - 1 && g[r + 1][c] != 1) {
                d[r][c] += dfs(r + 1, c, g);
            }
            if (c < m - 1 && g[r][c + 1] != 1) {
                d[r][c] += dfs(r, c + 1, g);
            }
        }
        return d[r][c];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> nums = {{0, 0, 0},
                                {0, 1, 0},
                                {0, 0, 0}};
    Solution solution;
    cout << solution.uniquePathsWithObstacles(nums);
    return 0;
}