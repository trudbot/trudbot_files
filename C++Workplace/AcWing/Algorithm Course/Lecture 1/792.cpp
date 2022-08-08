//
// Created by trudbot on 2022/7/3.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

vector<int> subtract(vector<int> a, vector<int> b)
{
    int curr = 0;
    vector<int> res;
    for(int i=0; i<a.size(); i++)
    {
        curr += a[i];
        if(i < b.size()) curr -= b[i];
        if(curr < 0)
        {
            //为负时， +10， 进位-1
            res.push_back(curr+10);
            curr = -1;
        }
        else
        {
            res.push_back(curr);
            curr = 0;
        }
    }
    return res;
}

bool compare(vector<int> va, vector<int> vb)
{
    if(va.size() != vb.size()) return va.size() > vb.size();
    for(int i=va.size()-1; i>=0; i--)
        if(va[i] != vb[i]) return va[i] > vb[i];
    return true;
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

    vector<int> res;
    //如果b比a大， 就计算b-a
    if(compare(va, vb))  res = subtract(va, vb);
    else
    {
        res = subtract(vb, va);
        cout <<"-";
    }

    int i = res.size()-1;
    while(i>0 && res[i] == 0) i--;//去除前导0
    while(i>=0) cout << res[i--];
    return 0;
}
