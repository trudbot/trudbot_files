//
// Created by trudbot on 2022/7/2.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int len = grid.size();
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                if(i==j || i+j==len-1) { if (grid[i][j] == 0) return false; }
                else if(grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};
