
//
// Created by trudbot on 2022/8/11.
//

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 1e5 + 10;
pair<int, int> dat[N];

int main() {
    FASTIO;
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        cout << "Case #" << t << ":";
        int n, x; cin >> n >> x;
        for(int i=0; i<n; i++)
        {
            int j; cin >> j;
            dat[i].first = (j - 1) / x;
            dat[i].second = i + 1;
        }

        sort(dat, dat + n);
        for(int i=0; i<n; i++)
            cout << " " << dat[i].second;
        cout << endl;
    }
    return 0;
}