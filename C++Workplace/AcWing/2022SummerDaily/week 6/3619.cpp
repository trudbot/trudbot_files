
//
// Created by trudbot on 2022/7/12.
//

#include <bits/stdc++.h>
using namespace std;

int month[] = {0, 0, 0, 0, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int M = 4, D = 12;
string week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, d, sum = 0;
    cin >> m >> d;
    for(int i=4; i<m; i++)
        sum += month[i];
    sum += d-D;

    cout << week[(sum+3)%7];
    return 0;
}