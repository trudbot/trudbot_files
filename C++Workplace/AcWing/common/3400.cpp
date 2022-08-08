
//
// Created by trudbot on 2022/8/1.
//

#include <bits/stdc++.h>
using namespace std;
int n, k, i;


int main()
{
    cin >> n >> k;
    int ans = 0;
    i = 10;
    while(n / i > 0)
    {
        ans += (n/i) * (i/10);
        i *= 10;
    }
    i /= 10;
    while (i != 0)
    {
        if(n >= (k+1) * i) ans += i;
        else if(n >= k*i) ans += (n - k*i + 1);
        n %= i, i /= 10;
    }
    cout << ans << endl;
    return 0;
}
