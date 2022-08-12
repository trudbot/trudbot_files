
//
// Created by trudbot on 2022/8/12.
//

//pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, from, to) for(int (i)=from; (i)<(to); (i)++)
#define each(a, x) for(auto &(a) : (x))
#define sz(x) (int)(x).size()
#define x first
#define y second
#define ins insert
#define pb push_back
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set

int main() {
    FASTIO;
    vi v = {1, 3, 9};
    rep(i, 0, sz(v)) cout << v[i] << " ";
    return 0;
}