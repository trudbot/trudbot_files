
//
// Created by trudbot on 2022/7/10.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
#define N 1010
int arr[N];
int seq[N];
int n, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++)
    {
        int t = 0;
        int j = i-1;
        while(j >= 1) t += arr[j--] > arr[i] ? 1 : 0;
        seq[arr[i]] = t;
        res += t;
    }
    for(int i=1; i<=n; i++)
        cout << seq[i] << " ";
    cout << endl << res;

    return 0;
}