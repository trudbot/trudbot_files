#include<bits/stdc++.h>

using namespace std;
#define ll long long


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findMax(vector<int> &a, int l, int r) {
        int ans = l;
        for(int i=l; i<=r; i++) {
            if(a[i] > a[ans]) {
                ans = i;
            }
        }
        return ans;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(vector<int> &nums, int l, int r) {
        if(l > r) {
            return nullptr;
        }
        int root = findMax(nums, l, r);
        auto* node = new TreeNode(nums[root]);
        node->left = dfs(nums, l, root-1);
        node->right = dfs(nums, root+1, r);
        return node;
    }
};

int main() {
    Solution s;

    return 0;
}
