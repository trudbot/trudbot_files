//
// Created by trudbot on 2022/6/19.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    static vector<int> printFromTopToBottom(TreeNode* root) {
        vector<int> v;
        TreeNode* temp;
        if(!root){
             return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return v;
    }
};
