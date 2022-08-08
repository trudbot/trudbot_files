//
// Created by trudbot on 2022/6/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int count[5010];
    int T, N, P, C;
    int i, j;
    int l, r;

    cin >> T;
    for(i=1; i<=T; i++)
    {
        memset(count, 0, 5010);
        cin >> N;
        for(j=0; j<N; j++)
        {
            cin>> l >> r;
            count[l]++;
            count[r+1]--;
        }

        for(j=2; j<=5001; j++)
            count[j] += count[j-1];

        cin >> P;
        cout << "Case #" << i << ":";
        while(P--)
        {
            cin >> C;
            cout << " " << count[C];
        }

        cout << endl;
    }

    return 0;
}
