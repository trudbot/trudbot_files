//
// Created by trudbot on 2022/7/5.
//

#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;

vector<int> div(vector<int> a, int b, int& r)
{
    vector<int> res;
    int curr = 0;
    for(int i=a.size()-1; i>=0; i--)
    {
        curr = curr*10 + a[i];
        res.push_back(curr/b);
        curr %= b;
    }
    r = curr;
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

    int r;
    vector<int> res = div(va, b, r);
    int i=0;
    while(i<res.size()-1 && res[i] == 0) i++;
    while(i<res.size()) cout << res[i++];
    cout << endl;
    cout << r << endl;
    return 0;
}
