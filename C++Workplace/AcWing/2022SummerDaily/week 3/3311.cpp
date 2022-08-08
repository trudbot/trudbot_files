//
// Created by trudbot on 2022/6/25.
//

#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;

int main() {
    int arr[MaxN];
    int T, N;
    int i, j;
    int max;
    cin >> T;
    int temp;
    for(i=1; i<=T; i++)
    {
        cin >> N;
        memset(arr, 0, N);
        for(j=0; j<N; j++)
            cin >> arr[j];

        for(j=N-1; j>=1; j--)
            arr[j] -= arr[j-1];

        max = 0;
        int r = 1, len;
        while(r < N)
        {
            len = 0;
            int curr = arr[r];
            for(r; r<N; r++)
            {
                if(arr[r] == curr)
                    len++;
                else
                    break;
            }
            if(len > max)
                max = len;
        }

        printf("Case #%d: %d\n", i, max+1);
    }
    return 0;
}
