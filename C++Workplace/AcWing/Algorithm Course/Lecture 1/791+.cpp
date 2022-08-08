//
// Created by trudbot on 2022/7/3.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

vector<int> add(vector<int> a, vector<int> b)
{
    if(a.size() < b.size())
        return add(b, a);
    vector<int> res;
    int curr = 0;
    for(int i=0; i<a.size(); i++)
    {
        curr += a[i];
        if(i < b.size()) curr += b[i];
        res.push_back(curr%10);
        curr /= 10;
    }
    if(curr != 0) res.push_back(curr);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    vector<int> va, vb;
    for(int i=a.size()-1; i>=0; i--) va.push_back(a[i]-'0');
    for(int i=b.size()-1; i>=0; i--) vb.push_back(b[i]-'0');

    vector<int> res = add(va, vb);
    for(int i=res.size()-1; i>=0; i--) cout << res[i];
    return 0;
}
