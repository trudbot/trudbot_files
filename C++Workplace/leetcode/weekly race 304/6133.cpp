
//
// Created by trudbot on 2022/7/31.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int i = 1, len = grades.size();
        while(len >= i) {
            len -= i++;
        }
        return i-1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> grades = {8, 8};
    Solution s;
    cout << s.maximumGroups(grades);
    return 0;
}