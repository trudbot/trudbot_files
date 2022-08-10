
//
// Created by trudbot on 2022/8/10.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode *tnp;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans;
        encode(root, ans);
        return ans;
    }

    void encode(tnp root, string &ans) {
        if(!root) {
            ans.append("null,");
            return;
        }
        ans.append(to_string(root->val) + ",");
        encode(root->left, ans);
        encode(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<string> dat;
        string tmp;
        for(auto &ch : data)
        {
            if(ch == ',') {
                dat.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(ch);
            }
        }
        int idx = 0;
        return decode(dat, idx);
    }

    tnp decode(vector<string> &dat, int &idx) {
        if(dat[idx] == "null") {
            return nullptr;
        }
        tnp node = new TreeNode(stoi(dat[idx]));
        node->left = decode(dat, ++idx);
        node->right = decode(dat, ++idx);
        return node;
    }
};

void dfs(tnp root) {
    if(!root) {
        return;
    }
    cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);
}


int main() {


    return 0;
}