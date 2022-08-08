
//
// Created by trudbot on 2022/8/2.
//

#include <bits/stdc++.h>
using namespace std;

int parse(char ch) {
    if(ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
    if(ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
    return ch - '0';
}

int translate(string x) {
    int l = 0, r = x.size()-1, ans = 0, sign = 1;

    if(x[0] == '-') sign = -1, l = 3;
    else l = 2;
    while(l <= r) {
        ans = 16 * ans + parse(x[l++]);
    }
    return ans;
}

int main() {
//    string x;
//    while(cin >> x) {
//        cout << translate(x) << endl;
//    }
    cout << ~(-1) << endl;
    return 0;
}