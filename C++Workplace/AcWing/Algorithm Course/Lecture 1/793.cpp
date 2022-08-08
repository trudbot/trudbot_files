//
// Created by trudbot on 2022/7/4.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

vector<int> multiply(vector<int> va, vector<int> vb)
{
    vector<int> res;
    int la = va.size(), lb = vb.size();
    res.resize(la+lb-1);
    for(int i=0; i<la; i++)
        for(int j=0; j<lb; j++)
            res[i+j] += va[i]*vb[j];

    int carry = 0;
    for(int i=0; i<=la+lb-2; i++)
    {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    if(carry != 0) res.push_back(carry);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;
    vector<int> va, vb;
    for(int i=a.length()-1; i>=0; i--) va.push_back(a[i]-'0');
    for(int i=b.length()-1; i>=0; i--) vb.push_back(b[i]-'0');

    vector<int> res = multiply(va, vb);
    int i = res.size()-1;
    while(i>0 &&res[i] == 0) i--;
    while(i >= 0) cout << res[i--];
    return 0;
}
