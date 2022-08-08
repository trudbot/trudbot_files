
//
// Created by trudbot on 2022/7/12.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int tim[N];//存放每种药服用的时间间隔
int last[N];//上一次服用某药的时间

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> tim[i];
        last[i] = -100;//初始化为一个很小的数， 保证第一次可以正常服用
    }

    int t, k;
    while ( m-- )
    {
        cin >> t >> k;
        int i;
        while( k--)
        {
            cin >> i;//i为当前要服用的药
            if(tim[i] == -1)//无间隔要求， 直接跳过
                continue;
            if(t - last[i] >= tim[i])//间隔够大， 可以服用， 更新最后一次服用时间为当前时间
                last[i] = t;
            else
                printf("Don't take %d at %d!\n", i, t);
        }
    }
    return 0;
}