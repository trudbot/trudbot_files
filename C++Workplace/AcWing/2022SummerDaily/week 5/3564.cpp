//
// Created by trudbot on 2022/7/4.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;

map<int, int> month = {{1, 31}, {2, 28}, {3, 31},
                       {4, 30}, {5, 31}, {6, 30},
                       {7, 31}, {8, 31}, {9, 30},
                       {10, 31}, {11, 30}, {12, 31}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int y, m, d;
    while(n--)
    {
        cin >> y >> m >> d;
        d++;
        if(d > month[m])
        {
            d = 1;
            m++;
        }
        if(m > 12)
        {
            m = 1;
            y++;
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}
