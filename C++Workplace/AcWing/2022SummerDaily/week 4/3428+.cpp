//
// Created by trudbot on 2022/6/29.
//
//暴力搜索

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m;

//curr为当前的盘子， rm为剩余的苹果数量， last为上一个盘中的苹果数量(保证递增序列)
int dfs(int curr, int rm, int last)
{
    if(curr == m+1)//盘子都枚举完了
    {
        if(rm == 0) return 1;
        else return 0;
    }

    int res = 0;
    for(int i=last; i<=rm; i++)
        res += dfs(curr+1, rm-i, i);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n >> m)
        cout << dfs(1, n, 0) << endl;
    return 0;
}
