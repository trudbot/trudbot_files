
//
// Created by trudbot on 2022/8/6.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string p, i;
    int l, T; cin >> T;

    for(int t=1; t<=T; t++)
    {
        cin >> i >> p;
        if(i.length() > p.length() || (i.length() == p.length() && i != p))
            printf("Case #%d: IMPOSSIBLE\n", t);
        else
        {
            bool flag = true;
            l = -1;
            for(char ch : i)
            {
                l = p.find(ch, l+1);
                if(l == -1)
                {
                    flag = false;
                    break;
                }
            }
            if(!flag) printf("Case #%d: IMPOSSIBLE\n", t);
            else printf("Case #%d: %d\n", t, p.length()-i.length());
        }
    }

    return 0;
}