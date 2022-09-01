//
// Created by trudbot on 2022/9/1.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        char vo[] = {'a', 'e', 'i', 'o', 'u'};
        s.insert(0, "0");
        unordered_map<char, vector<int>> pref;
        for(int i=0; i<5; i++) {
            pref[vo[i]].resize(s.length());
            pref[vo[i]][0] = 0;
        }
        for(int i=1; i<s.length(); i++) {
            for(int j=0; j<5; j++) {
                pref[vo[j]][i] = pref[vo[j]][i-1] + (vo[j] == s[i]);
            }
        }

        auto check = [&](int l, int r) -> bool {
            bool ans = true;
            for(int i=0; i<5; i++) {
                ans &= ((pref[vo[i]][r] - pref[vo[i]][l-1]) % 2 == 0);
            }
            return ans;
        };

        for(int i=s.length(); i>=0; i--) {
            for(int j=1; j+i <= s.length(); j++) {
                if(check(j, j+i-2)) {
                    return i;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.findTheLongestSubstring("eleetminicoworoep");
}
