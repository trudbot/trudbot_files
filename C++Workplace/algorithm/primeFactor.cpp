//
// Created by trudbot on 2022/6/26.
//
//试除法分解质因数

#include <bits/stdc++.h>

using namespace std;

unordered_map<long, long> divide(long x)
{
    unordered_map<long, long> res;
    for(long i=2; i<=x/i; i++)
    {
        if(x % i == 0)
        {
            long count = 0;
            while(x % i == 0){
                count++;
                x /= i;
            }
            res[i] = count;
        }
    }
    if(x > 1)
        res[x] = 1;
    return res;
}

int main() {
    long num;
    cin >> num;
    auto pfs = divide(num);

    //应用举例-找一个数x使得 x*num是完全平方数
    long res = 1;
    for(auto & pf : pfs)
    {
        if(pf.second % 2 == 1)
            res *= pf.first;
    }
    cout << res;
    return 0;
}
