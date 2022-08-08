//
// Created by trudbot on 2022/7/2.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define N 10001
struct node{
    int c = 0;
    vector<int> child;
};

node Tree[N];
int colors[N];


int Count = 0;
void dfs(int root, int cc)
{
    if(cc != colors[root])
    {
        cc = colors[root];
        Count++;
    }
    for(auto ch : Tree[root].child)
        dfs(ch, cc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int p;
    for(int i=2; i<=n; i++)
    {
        cin >> p;
        Tree[p].child.push_back(i);
    }

    for(int i=1; i<=n; i++)
        cin>>colors[i];
    dfs(1, 0);
    cout << Count;
    return 0;
}
