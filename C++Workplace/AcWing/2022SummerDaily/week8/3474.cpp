
//
// Created by trudbot on 2022/7/28.
//

#include <bits/stdc++.h>
#define vi vector<int>
#define vp vector<pair<int, int>>
using namespace std;
int A;

int main() {
    int n; cin >> n;
    vi l, r;
    vp data;
    while(n --)
    {
        int a, b; cin >> a >> b;
        if(b == 0) A = a;
        else data.push_back({a, b});
    }
    sort(data.begin(), data.end());
    for(auto i : data)
    {
        if(i.first < A && i.second == 1) l.push_back(i.first);
        else if(i.first > A && i.second == -1) r.push_back(i.first);
    }

    if(l.size() == r.size()) cout << "Cannot fall!";
    else if(l.size() > r.size()) cout << 100 - l[l.size()-r.size()-1];
    else cout << r[l.size()];

    return 0;
}