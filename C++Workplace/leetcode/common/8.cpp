#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0, sign = 1;
        int l = 0, r = s.size()-1;
        while(s[l] == ' ') l++;
        if(s[l] == '-') l++, sign = -1;

        while(l <= r && s[l] >= '0' && s[l] <= '9')
        {
            ans = ans * 10 + s[l++] - '0';
            if(ans >= INT_MAX) return INT_MAX;
            if(sign == -1 && sign*ans <= INT_MIN) return INT_MIN;
        }
        return sign*ans;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("-91283472332");
    return 0;
}