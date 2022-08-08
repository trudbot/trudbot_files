
//
// Created by trudbot on 2022/8/7.
//

#include <bits/stdc++.h>

#define pb push_back;
#define uset unordered_set
#define umap unordered_map
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

bool judge(int x)
{
    for(int i=2; i*i<x; i++)
    {
        if(x % (i*i) == 0)
            return true;
    }
    return false;
}

int main() {
    FASTIO
    int x;
    while(cin >> x)
    {
        if(judge(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}