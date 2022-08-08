
//
// Created by trudbot on 2022/7/15.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
vector<int> days;
int cost[3];
int memo[400];
int n;

int dfs(int curr)
{
    if(memo[curr] != -1) return memo[curr];
    if(curr > days.size()) return 0;

    memo[curr] = 1e9;
    int i = curr + 1;
    memo[curr] = min(memo[curr], cost[0] + dfs(i));
    while(days[i] < days[curr] + 7 && i < days.size()) i++;
    memo[curr] = min(memo[curr], cost[1] + dfs(i));
    while(days[i] < days[curr] + 30 && i < days.size()) i++;
    memo[curr] = min(memo[curr], cost[2] + dfs(i));
    return memo[curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    days.resize(n);
    for(int i=0; i<n; i++) cin >> days[i], memo[i] = -1;
    for(int & i : cost) cin >> i;

    cout << dfs(0);
    return 0;
}