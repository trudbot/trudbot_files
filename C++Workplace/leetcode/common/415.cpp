
//
// Created by trudbot on 2022/7/26.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1, j = num2.length()-1, carry = 0;
        string ans;
        while(i >=0 || j >= 0 || carry != 0)
        {
            carry += (i >= 0 ? num1[i]-'0' : 0);
            carry += (j >= 0 ? num2[j]-'0' : 0);
            ans += (char)('0' + carry);
            carry /= 10;
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution s;
    cout << s.addStrings("11", "123");
    return 0;
}