//
// Created by trudbot on 2022/7/3.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double x, l, r, m;
    scanf("%lf", &x);
    l = -10000, r = 10000;
    while(r-l > 1e-8)
    {
        m = (l+r)/2;
        if(m*m*m < x) l = m;
        else r = m;
    }
    printf("%.6lf", l);
    return 0;
}
