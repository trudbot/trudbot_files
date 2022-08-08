
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
    typedef TreeNode *tnp;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }

    tnp ans;

    bool dfs(tnp root, tnp p, tnp q) {
        if (!root) {
            return false;
        }
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);

        if ((l && r) || ((root == p || root == q) && (l || r))) {
            ans = root;
        }
        return l || r || root == p || root == q;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}