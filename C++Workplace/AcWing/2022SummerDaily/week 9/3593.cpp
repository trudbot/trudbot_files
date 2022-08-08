
//
// Created by trudbot on 2022/8/1.
//

#include <bits/stdc++.h>
using namespace std;

void foo(string s)
{
    bool flag = false;
    int l = 0, r = s.size()-1, i = 0;
    while(i <= r)
    {
        if(!flag && s[i] != ' ')
            flag = true, l = i;
        else if(flag && s[i] == ' ')
            flag = false, cout << i - l + 1 << " ";
        i++;
    }
}

int main() {
    string line;
    getline(cin, line);
    foo(line);
    return 0;
}