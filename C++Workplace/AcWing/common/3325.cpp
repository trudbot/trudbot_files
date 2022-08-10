
//
// Created by trudbot on 2022/8/9.
//

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main()
{
    string x;
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        vi kick, start;
        cin >> x;
        int i = 0;
        while((i = x.find("KICK", i)) != string::npos)
        {
            kick.push_back(i);
            i++;
        }

        i = 0;
        while((i = x.find("START", i)) != string::npos)
        {
            start.push_back(i);
            i++;
        }


        int n = kick.size(), m = start.size(), ans = 0;
        int j = 0;
        for(i=0; i<n; i++)
        {
            while(j < m && start[j] < kick[i]) j++;
            ans += m-j;
        }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}