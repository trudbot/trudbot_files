
//
// Created by trudbot on 2022/8/5.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef TreeNode* tnp;
    vector<vector<int>> findPath(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        dfs(root, sum, ans);
        return ans;
    }
    vector<int> path;

    void dfs(tnp root, int sum, vector<vector<int>> &ans) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && !root->left && !root->right) {
            ans.push_back(path);
        } else if(sum > 0) {
            dfs(root->left, sum, ans);
            dfs(root->right, sum, ans);
        }
        path.pop_back();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution s;
    s.findPath(NULL, )
    return 0;
}