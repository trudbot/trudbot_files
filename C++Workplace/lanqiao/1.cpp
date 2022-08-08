//
// Created by trudbot on 2022/6/27.
//

#include <bits/stdc++.h>

using namespace std;

int nums[55];

int countCow(int n)
{
    if(n <= 4)
        return n;
    if(nums[n] == 0)
        nums[n] = countCow(n-1) + countCow(n-3);
    return nums[n];
}

int main() {
    int n;
    cin >> n;
    while(n != 0)
    {
        cout << countCow(n) << endl;
        cin >> n;
    }
}
