
//
// Created by trudbot on 2022/7/21.
//

#include <bits/stdc++.h>
using namespace std;

int st[1000];

bool judge(int x)
{
    int i, j, k;
    i = x%10, j = (x/10)%10, k = x/100;
    return pow(i, 3) + pow(j, 3) + pow(k, 3) == x;
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        if(n == 0) break;
        int cnt = 0;
        for(int i=m; i<=n; i++)
        {
            if(st[i] == 0)
                st[i] = judge(i) ? 1 : -1;
            if(st[i] == 1)
                cout << i << " ", cnt++;
        }
        if(cnt == 0) cout << "no";
        cout << endl;
    }
    return 0;
}