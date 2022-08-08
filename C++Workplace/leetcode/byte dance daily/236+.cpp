
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<tnp, tnp> parent;
        parent[root] = NULL;
        unordered_map<tnp, bool> st;
        dfs(root, parent);

        while(p) {
            st[p] = true;
            p = parent[p];
        }
        while(!st[q]) {
            q = parent[q];
        }
        return q;
    }

    void dfs(tnp r, unordered_map<tnp, tnp> &parent) {
        if(r->left) {
            parent[r->left] = r;
            dfs(r->left, parent);
        }
        if(r->right) {
            parent[r->right] = r;
            dfs(r->right, parent);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}