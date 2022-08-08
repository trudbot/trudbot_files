//
// Created by trudbot on 2022/6/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];

    int max = 0, count, i, j;
    for(i=0; i<n; i++)
    {
        count = 1;
        for(j=i+1; j<n; j++)
        {
            if(nums[j] <= nums[j-1]*2)
                count++;
            else
                break;
        }
        i = j-1;
        if(count > max)
            max = count;
    }
    cout << max;
    return 0;
}

