
//
// Created by trudbot on 2022/8/6.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        string num; cin >> num;
        int sum = 0;
        for (auto &ch: num) sum += ch - '0';
        if(sum % 9 == 0) {
            num.insert(1, "0");
        }
        else
        {
            string s;
            s.push_back('9' - sum%9);
            cout << s << endl;
            int i = 0;
            while (i < num.size() && num[i] <= s[0]) i++;
            num.insert(i, s);
        }
        printf("Case #%d: ", t);
        cout << num << endl;
    }
    return 0;
}