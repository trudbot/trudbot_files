//
// Created by trudbot on 2022/6/28.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    int n, t;
    cin >> n;
    while(n--)
    {
        cin>>t;
        s.insert(t);
    }
    for(auto i : s)
        cout << i << " ";
    return 0;
}
