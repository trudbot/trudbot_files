//
// Created by trudbot on 2022/6/30.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
int a, b;

inline void fout(int n)
{
    if(n < 10) cout << n;
    else cout << (char)(n+'A'-10);
}

void convert(int n)
{
    if(n < b) fout(n);
    else
    {
        convert(n/b);
        fout(n % b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n; int num = 0;
    cin >> a >> n >> b;
    for(int count=0; count<n.length(); count++)
    {
        int curr = n.length()-count-1;
        if(isdigit(n[curr]))
            num += (int)pow(a, count)*(n[curr]-'0');
        else if(isupper(n[curr]))
            num += (int)pow(a, count)*(n[curr]-'A'+10);
        else
            num += (int)pow(a, count)*(n[curr]-'a'+10);
    }
    convert(num);
    return 0;
}
