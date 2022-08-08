//
// Created by trudbot on 2022/7/8.
//

#include <bits/stdc++.h>

using namespace std;
string pre, in;

void dfs(int l1, int r1, int l2, int r2)
{
    if(l1 > r1) return;
    int i=l2;
    while(in[i] != pre[l1]) i++;
    dfs(l1+1, l1+i-l2, l2, i-1);
    dfs(r1-r2+i+1, r1, i+1, r2);
    cout << pre[l1];
}

int main() {
    while(cin >> pre >> in)
    {
        dfs(0, pre.size()-1, 0, in.size()-1);
        cout << endl;
    }
    return 0;
}
