
//
// Created by trudbot on 2022/7/13.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N], n;
int l, r;

int Solution()
{
    int thisL = 0;
    int MaxSum = 0, ThisSum = 0;
    l = r = 0;
    for(int i=0; i<n; i++)
    {
        ThisSum += arr[i];
        if(ThisSum < 0)
        {
            ThisSum = 0;
            thisL = i + 1;
            continue;
        }
        if(MaxSum == 0 || ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            l = thisL, r = i;
        }
    }
    return MaxSum;
}

int main()
{
    while(cin >> n)
    {
        for(int i=0; i<n; i++) cin >> arr[i];
        cout << Solution() << " " << l << " " << r;
        cout << endl;

    }
    return 0;
}