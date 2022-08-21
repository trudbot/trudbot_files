
//
// Created by trudbot on 2022/8/21.
//

//#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;
__attribute__((unused)) int io_ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}();
#define rep(i, a, b) for(int (i)=a; (i)<(b); (i)++)

int n;
int sudoku[40][40];
unordered_map<int, int> cnt;

bool check() {
    for(int i=1; i<=n*n; i++) {
        if(cnt[i] != 1) {
            cnt.clear();
            return false;
        }
    }
    cnt.clear();
    return true;
}

bool solve() {
    //检查行
    rep(row, 1, n*n+1) {
        rep(col, 1, n*n + 1) {
            cnt[sudoku[row][col]]++;
        }
        if(!check()) {
            return false;
        }
    }

    //检查列
    rep(col, 1, n*n+1) {
        rep(row, 1, n*n+1) {
            cnt[sudoku[row][col]] ++;
        }
        if(!check()) {
            return false;
        }
    }

    //检查小方格
    for(int i=1; i<n*n; i += n) {
        for(int j=1; j<n*n; j += n) {
            rep(row, i, i+n) {
                rep(col, j, j+n) {
                    cnt[sudoku[row][col]]++;
                }
            }
            if(!check()) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int T; cin >> T;
    rep(t, 1, T+1) {
        cout << "Case #" << t << ": ";
        cin >> n;
        rep(i, 1, n*n+1) {
            rep(j, 1, n*n+1) {
                cin >> sudoku[i][j];
            }
        }
        cout << (solve() ? "Yes" : "No") << endl;
    }

    return 0;
}