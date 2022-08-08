
//
// Created by trudbot on 2022/8/6.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

class Solution {
public:
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        vis.resize(S.size(), false);
        n = S.size();
        vector<string> ans;
        dfs(S, ans);
        return ans;
    }

    int n;
    string path;
    vector<bool> vis;

    void dfs(string &s, vector<string> &ans) {
        if(path.size() == n) {
            ans.push_back(path);
        }
        for(int i=0; i<n; i++) {
            if(!vis[i] && (i==0 || s[i] != s[i-1] || vis[i-1])) {
                path.push_back(s[i]);
                vis[i] = true;
                dfs(s, ans);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
};

int main() {
    string s = "qqe";
    Solution solution;
    auto ans = solution.permutation(s);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}