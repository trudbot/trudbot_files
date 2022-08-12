
//
// Created by trudbot on 2022/8/12.
//
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(from, to) for(int i=from; i<(to); i++)

int MaxFreq(string &s)
{
    map<char, int> mp;
    rep(0, s.size()) mp[s[i]]++;
    int res = 0;
    for(auto p : mp)
        res = max(res, p.second);
    return res;
}

int main() {
    FASTIO;
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        cout << "Case #" << t << ": ";
        string s; cin >> s;
        int n = (int)s.size();
        int mx = MaxFreq(s);
        if(n - mx < mx)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        vector<pair<char, int>> pos(n);
        rep(0, n)
            pos[i].first = s[i], pos[i].second = i;
        sort(pos.begin(), pos.end());

        rep(0, n)
            s[pos[(i + mx) % n].second] = pos[i].first;

        cout << s << endl;
    }
    return 0;
}