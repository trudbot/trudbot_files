
//
// Created by trudbot on 2022/7/27.
//

#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;

vll partition(ll N, ll A) {
    vll ans;
    if(A == 0) return ans;
    else if(N > A) return partition(N-1, A);
    else
    {
        ans.push_back(N);
        vll ne = partition(N-1, A-N);
        ans.insert(ans.end(), ne.begin(), ne.end());
        return ans;
    }
}

int main() {

    vll ans = partition(3, 4);
    for(ll i : ans) cout << i << " ";
    return 0;
}