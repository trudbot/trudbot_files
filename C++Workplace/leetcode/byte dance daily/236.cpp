
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<tnp, int> level;
        unordered_map<tnp, tnp> parent;

        auto bfs = [&level, &parent] (tnp root) -> void {
            level[root] = 1;
            queue<tnp> q;
            q.push(root);

            while(!q.empty()) {
                tnp t = q.front();
                q.pop();
                if(t->left) {
                    level[t->left] = level[t] + 1;
                    q.push(t->left);
                    parent[t->left] = t;
                }
                if(t->right) {
                    level[t->right] = level[t] + 1;
                    q.push(t->right);
                    parent[t->right] = t;
                }
            }
        };

        bfs(root);

        auto Find = [&level, &parent] (tnp p, tnp q) -> tnp {
            while(level[p] > level[q]) {
                p = parent[p];
            }
            while(level[q] > level[p]) {
                q = parent[q];
            }
            while(p != q) {
                p = parent[p];
                q = parent[q];
            }
            return p;
        };

        return Find(p, q);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}