//
// Created by trudbot on 2022/6/27.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int len, N;
    int p, q;
    cin >> len >> N;
    int arr[len+1];
    for(int i=1; i<=len; i++)
    {
        arr[i] = i;
    }

    while(N--)
    {
        cin >> p >> q;
        if(p == 0)
            sort(arr+1, arr+1+q, greater<int>());
        else
            sort(arr+q, arr+1+len);
    }

    for(int i=1; i<=len; i++)
        printf("%d ", arr[i]);
    return 0;
}
