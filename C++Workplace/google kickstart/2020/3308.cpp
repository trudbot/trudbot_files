#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 10;
int n, a[N];

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            a[i] -= a[i-1];
        }
        bool flag;
        for(int i=2; i<=n; i++) {
            if(a[i] == 0) {
                continue;
            } else {
                flag = a[i] > 0;
                a[1] = a[i];
                break;
            }
        }
        int ans = 0, num = 0;
        for(int i=1; i<=n; i++) {
            if(a[i] == 0) {
                continue;
            } else if((a[i] > 0) ^ flag) {
                num = 2, flag = !flag;
            } else {
                if(num == 4) {
                    num = 1, ans ++;
                } else {
                    num++;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
