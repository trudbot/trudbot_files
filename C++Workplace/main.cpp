#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 10;
int n, m;
int num[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int x, lackNum = n;
    while (m > 0) {
        if (lackNum > m) {
            while (m--) {
                cout << '0';
            }
        } else {
            m -= lackNum-1;
            for (int i = 1; i < lackNum; i++) {
                cin >> x;
                cout << '0';
                num[x]++;
            }

            lackNum = 0;
            for (int i = 1; i <= n; i++) {
                if (num[i] == 0) {
                    lackNum++;
                }
            }
            while (m--) {
                cin >> x;
                if(num[x] == 0) {
                    lackNum--;
                }
                num[x] ++;
                if(lackNum == 0) {
                    break;
                } else {
                    cout << '0';
                }
            }
            if(lackNum == 0) {
                cout << '1';
                for(int i=1; i<=n; i++) {
                    lackNum += --num[i] == 0;
                }
            }
        }
    }

    return 0;
}
