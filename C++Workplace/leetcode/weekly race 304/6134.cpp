
//
// Created by trudbot on 2022/7/31.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int x, int y) {
        int n = (int) edges.size(), cnt = 0;
        vector<int> s1(n, -1), s2(n, -1);
        while (x != -1) {
            if (s1[x] != -1) {
                break;
            }
            s1[x] = cnt++;
            x = edges[x];
        }
        cnt = 0;
        while (y != -1) {
            if (s2[y] != -1) {
                break;
            }
            s2[y] = cnt++;
            y = edges[y];
        }

        int d = -1, id = -1;
        for (int i = 0; i < n; ++i) {
            if(s1[i] != -1 && s2[i] != -1) {
                if(d == -1 || min(s1[i], s2[i]) < d) {
                    d = min(s1[i], s2[i]);
                    id = i;
                }
            }
        }
        return id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> edges = {5, 3, 1, 0, 2, 4, 5};
    Solution s;
    cout << s.closestMeetingNode(edges, 6, 3);
    return 0;
}