
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
    TreeNode *convert(TreeNode *root) {
        return dfs(root).first;
    }

    pair<tnp, tnp> dfs(tnp root) {
        pair<tnp, tnp> ans;
        if(root->left) {
            auto l = dfs(root->left);
            l.second->right = root;
            root->left = l.second;
            ans.first = l.first;
        } else {
            ans.first = root;
        }

        if(root->right) {
            auto r = dfs(root->right);
            r.first->left = root;
            root->right = r.first;
            ans.second = r.second;
        } else {
            ans.second = root;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}