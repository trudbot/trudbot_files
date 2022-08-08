//
// Created by trudbot on 2022/7/1.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;


int A, B, C;
unordered_set<int> cVal;
set<pair<int, int>> ab;

void dfs(int a, int b, int c)
{
    if(ab.count({a, b}))
        return;
    ab.insert({a, b});
    cVal.insert(c);

    if(a != 0)
    {
        if(a+b <= B) dfs(0, a+b, c);
        else dfs(a-(B-b), B, c);
        if(a+c <= C) dfs(0, b, a+c);
        else dfs(a-(C-c), b, C);
    }

    if(b != 0)
    {
        if(b+a <= A) dfs(a+b, 0, c);
        else dfs(A, b-(A-a), c);
        if(b+c <= C) dfs(a, 0, b+c);
        else dfs(a, b-(C-c), C);
    }

    if(c != 0)
    {
        if(c+a <= A) dfs(a+c, b, 0);
        else dfs(A, b, c-(A-a));
        if(c+b <= B) dfs(a, b+c, 0);
        else dfs(a, B, c-(B-b));
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> A >> B >> C)
    {
        dfs(0, 0, C);
        cout << cVal.size() << endl;
        cVal.clear();
        ab.clear();
    }
    return 0;
}
