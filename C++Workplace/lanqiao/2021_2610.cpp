//
// Created by trudbot on 2022/6/27.
//

#include <bits/stdc++.h>

using namespace std;

int f(int n)
{
    int res = 1;
    while(n != 1)
        res *= n--;
    return res;
}

int C(int n, int i)
{
    if(i == 0)
        return 1;
    if(i == 1)
        return n;
    int res = 1;
    for(int j=1; j<=i; j++)
        res *= n--;
    return res/f(i);
}

int main() {
    int N;
    int res;
    int max = 1;
    int tier = 1;
    cin >> N;
    while(max < N)
    {
        res += tier++;
        max = C(tier-1, (tier-1)/2);
    }
    int i=0;
    do{
        res++;
    }while(N != C(tier-1, i++));

    cout << res;

    return 0;
}
