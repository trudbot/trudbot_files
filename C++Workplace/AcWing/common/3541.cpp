
//
// Created by trudbot on 2022/7/31.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> ps(n);
    for(int i=0; i<n; i++) {
        cin >> ps[i].first >> ps[i].second;
    }
    sort(ps.begin(), ps.end());

    cout << ps[0].first << " " << ps[0].second;
    return 0;
}