//
// Created by trudbot on 2022/6/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int, int>> bars;

    int T, N, P, C;
    int l, r;
    int i, j, k;
    int count;
    cin >> T;
    for(i=1; i<=T; i++)
    {
        cin >> N;
        for(j=0; j<N; j++)
        {
            cin >> l >> r;
            bars.emplace_back(l, r);
        }

        cin >> P;
        cout << "Case #" << i << ":";
        while(P--)
        {
            count = 0;
            cin>> C;
            for(auto p : bars)
            {
                if(C>=p.first && C<=p.second)
                    count++;
            }
            cout << " " << count;
        }

        bars.clear();
        cout << endl;
    }

    return 0;
}
