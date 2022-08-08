
//
// Created by trudbot on 2022/7/19.
//

#include <bits/stdc++.h>
using namespace std;
#define N 55
int ne[N], n;
int cnt = 1;

void Solution()
{
    int curr = 1;
    while(ne[curr] != curr)
    {
        if(cnt == 2)
        {
            cout << ne[curr] << " ";
            ne[curr] = ne[ne[curr]];
            cnt = 1;
        }
        else cnt++;
        curr = ne[curr];
    }
    cout << curr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i=1; i<n; i++) ne[i] = i+1;
        ne[n] = 1;
        Solution();
    }
    return 0;
}