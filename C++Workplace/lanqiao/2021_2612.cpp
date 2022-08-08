//
// Created by trudbot on 2022/6/27.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 1;
    int N;
    int count = 1;
    int w = 1;
    cin >> N;

    while(sum < N)
    {
        w *= 3;
        sum += w;
        count++;
    }

    cout << count;

    return 0;
}
