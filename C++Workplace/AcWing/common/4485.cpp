//
// Created by trudbot on 2022/6/25.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    int temp;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        a += temp;
    }
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        b += temp;
    }
    if(a >= b)
        cout << "Yes";
    else
        cout<< "No";

    return 0;
}
