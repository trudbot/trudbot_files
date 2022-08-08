//
// Created by trudbot on 2022/7/5.
//当两个数其中一个较小能被c++整型所储存时， 可以使用另一种方法

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;

vector<int> eval(vector<int> a, int b)
{
    vector<int> res;
    int curr = 0;
    for(int i : a)
    {
        curr += i * b;
        res.push_back(curr % 10);
        curr /= 10;
    }
    if(curr != 0) res.push_back(curr);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a;
    int b;
    cin >> a >> b;
    vector<int> va;
    for(int i=a.length()-1; i>=0; i--) va.push_back(a[i]-'0');

    vector<int> res = eval(va, b);
    int last = res.size()-1;
    while(last>0 && res[last] == 0) last--;
    while(last>=0) cout << res[last--];
    return 0;
}
