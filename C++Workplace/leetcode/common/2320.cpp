//
// Created by trudbot on 2022/7/2.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        int res = Count(n);
        return res*res;
    }

    inline int Count(int n)
    {
        if(n <= 2) return n+1;
        int f1 = 2, f2 = 3, curr;
        for(int i=3; i<=n; i++)
        {
            curr = f1+f2;
            f1 = f2;
            f2 = curr;
        }
        return curr;
    }
};
