//
// Created by trudbot on 2022/7/7.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
int num[26] = {1, 2, 3,
               1, 2, 3,
               1, 2, 3,
               1, 2,3,
               1, 2, 3,
               1, 2, 3, 4,
               1, 2, 3,
               1, 2, 3, 4};

int pos[26] = {1, 1, 1,
               2, 2, 2,
               3, 3, 3,
               4, 4, 4,
               5, 5, 5,
               6, 6, 6,
               6, 7, 7,
               7, 8, 8, 8, 8};

int Solution(const string& str)
{
    int ans = 0;
    int lp = 0;
    for(char ch : str)
    {
        int i = ch-'a';
        ans += num[i];
        if(pos[i] == lp)
            ans += 2;
        lp = pos[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    while(cin >> str)
        cout << Solution(str) << endl;
    return 0;
}
