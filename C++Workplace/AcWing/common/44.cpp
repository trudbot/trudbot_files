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
    static vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        int depth;
        int count;
        TreeNode* temp;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        depth = 0;
        count = 1;
        res.emplace_back();

        while(true){
            while(!q1.empty()){
                temp = q1.front();
                q1.pop();
                res[depth].push_back(temp->val);
                if(temp->left){
                    q2.push(temp->left);
                }
                if(temp->right){
                    q2.push(temp->right);
                }
            }
            if(q2.empty()){
                break;
            }
            else{
                depth++;
                q1.swap(q2);
                res.emplace_back();
            }
        }
        if(res[res.size()-1].empty()){
            res.pop_back();
        }
        return res;
    }
};
