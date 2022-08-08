
//
// Created by trudbot on 2022/7/18.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    while(a != b)
    {
        if(a > b) a /= 2;
        else b /= 2;
    }
    cout << a;
    return 0;
}