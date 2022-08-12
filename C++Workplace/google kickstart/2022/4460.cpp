
//
// Created by trudbot on 2022/8/12.
//

#include <bits/stdc++.h>

using namespace std;

bool isSpecial(char C)
{
    return C == '#' || C == '@' || C == '*' || C == '&';
}

int main()
{
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        bool st[6]= {false};
        int n; cin >> n;
        string s; cin >> s;
        for(int i=0; i<n; i++)
        {
            if(isupper(s[i])) st[2] = true;
            else if(islower(s[i])) st[3] = true;
            else if(isdigit(s[i])) st[4] = true;
            else if(isSpecial(s[i])) st[5] = true;
        }

        if(!st[2]) s.push_back('A');
        if(!st[3]) s.push_back('a');
        if(!st[4]) s.push_back('0');
        if(!st[5]) s.push_back('#');

        while(s.size() < 7) s.push_back('a');
        printf("Case #%d: %s\n", t, s.c_str());
    }
    return 0;
}