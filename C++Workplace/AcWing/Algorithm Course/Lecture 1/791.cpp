//
// Created by trudbot on 2022/7/3.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;

char eval(char a, char b, int & carry)
{
    int res = a+b-'0'-'0'+carry;
    carry = res/10;
    res %= 10;
    return (char)(res+'0');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b, res;
    getline(cin, a);
    getline(cin, b);
    int la = a.length()-1, lb = b.length()-1;
    int ml = max(la, lb);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i = 0, carry = 0; char cha, chb;
    while(i <= ml)
    {
        if(i > la) cha = '0';
        else cha = a[i];
        if(i > lb) chb = '0';
        else chb = b[i];

        res += eval(cha, chb, carry);
        i++;
    }
    if(carry != 0) res += (char)(carry+'0');
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}
