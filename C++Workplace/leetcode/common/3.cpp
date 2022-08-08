//
// Created by trudbot on 2022/7/5.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int res = 0, i, j = 0, n = s.length();
        unordered_map<char, int> hash;
        hash[s[0]] = 0;
        for(i=0; i<n; i++)
        {
            if(n-i <= res) break;
            for(j++; j<n; j++)
            {
                if(hash.count(s[j]) != 0) break;
                else hash[s[j]] = j;
            }
            res = max(res, (int)hash.size());
            if(j == n) break;
            while(i < hash[s[j]])
                hash.erase(s[i++]);
            hash[s[j]] = j;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("umvejcuuk");


}
