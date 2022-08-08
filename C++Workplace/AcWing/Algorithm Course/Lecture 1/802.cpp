
//
// Created by trudbot on 2022/7/23.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
unordered_map<int, int> w;
int nums[N], len, pre[N];

int high(int x)
{
    int l = 1, r = len;
    while (l < r)
    {
        int m = (l+r) >> 1;
        if(nums[m] < x) l = m+1;
        else r = m;
    }
    return l;
}

int low(int x)
{
    int l = 1, r = len;
    while (l < r)
    {
        int m = (l+r+1) >> 1;
        if(nums[m] > x) r = m-1;
        else l = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        int x, c;
        cin >> x >> c;
        w[x] += c;
        nums[++len] = x;
    }

    sort(nums+1, nums+1+len);
    {
        int j = 1;
        for(int i=1; i<=len; i++)
            if(nums[i] != nums[j])
                nums[++j] = nums[i];
        len = j;
    }

    for(int i=1; i<=len; i++)
        pre[i] = pre[i-1] + w[nums[i]];

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l = high(l), r = low(r);
        if(l > r) cout << 0 << endl;
        else cout << pre[r] - pre[l-1] << endl;
    }

    return 0;
}