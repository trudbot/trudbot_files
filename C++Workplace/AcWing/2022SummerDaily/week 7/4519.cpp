
//
// Created by trudbot on 2022/7/17.
//

#include <bits/stdc++.h>
using namespace std;
int n, res;
int nums[20];
bool vis[20];

bool judge(int x)
{
    int i = (int)sqrt(x);
    return i*i == x;
}

void dfs(int last, int remain)
{
    if(remain == 0)
    {
        res++;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i] || (nums[i-1] == nums[i] && !vis[i-1]))
            continue;
        if(last == -1 || judge(last+nums[i]))
        {
            vis[i] = true;
            dfs(nums[i], remain - 1);
            vis[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> nums[i];
    sort(nums+1, nums+1+n);
    nums[0] = -1;
    dfs(-1, n);
    cout << res;
    return 0;
}