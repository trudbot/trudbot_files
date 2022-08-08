//
// Created by trudbot on 2022/6/29.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, t;
    priority_queue<int, vector<int>, greater<> > heap;
    cin >> N;
    while(N--)
    {
        cin >> t;
        heap.push(t);
    }

    int a, b, res = 0;
    while(heap.size() != 1)
    {
        a = heap.top(); heap.pop();
        b = heap.top(); heap.pop();
        res += a+b;
        heap.push(a+b);
    }

    cout << res;
    return 0;
}
