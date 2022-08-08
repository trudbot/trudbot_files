//
// Created by trudbot on 2022/7/3.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

int Tree[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> Tree[i];
    int k; cin >> k;
    if((int)pow(2, k-1) > n)
    {
        cout << "EMPTY";
        return 0;
    }
    for(int i=(int)pow(2, k-1); i<=min(n, (int)pow(2, k)-1); i++)
        cout << Tree[i] << " ";
    return 0;
}
