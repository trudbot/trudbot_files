
//
// Created by trudbot on 2022/8/3.
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
    typedef TreeNode *tr;

    vector<vector<int>> printFromTopToBottom(TreeNode *root) {
        stack<tr> s1, s2;
        vector<vector<int>> ans;
        unordered_map<tr, int> level;
        if(root) {
            level[root] = 0;
            s1.push(root);
        }

        auto insertLeft = [&s2] (tr tar) -> void {
            if(tar->left) {
                s2.push(tar->left);
            }
        };

        auto insertRight = [&s2] (tr tar) -> void {
            if(tar->right) {
                s2.push(tar->right);
            }
        };

        auto bfs = [&] () -> void {
            while(!s1.empty()) {
                tr curr = s1.top();
                s1.pop();
                if(ans.size() < level[curr] + 1) {
                    ans.push_back({});
                }
                ans[level[curr]].push_back(curr->val);
                if(level[curr] % 2 == 0) {
                    insertLeft(curr);
                    insertRight(curr);
                } else {
                    insertRight(curr);
                    insertLeft(curr);
                }
                level[curr->left] = level[curr->right] = level[curr] + 1;
            }
        };

        while (!s1.empty()) {
            bfs();
            swap(s1, s2);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> res;
    auto check = [&res] (int num) -> void {
        if(num & 1) {
            res.push_back(num);
        }
    };

    for(int i=1; i<=100; i++) {
        check(i);
    }

    return 0;
}