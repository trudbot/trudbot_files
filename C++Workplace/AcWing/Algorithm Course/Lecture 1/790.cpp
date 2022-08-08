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

    double x;
    scanf("%lf", &x);
    if(x >= 0) printf("%.6lf", pow(x, 1.0/3));
    else printf("%.6lf", -1* pow(-1*x, 1.0/3));
    return 0;
}
