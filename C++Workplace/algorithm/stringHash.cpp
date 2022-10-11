//
// Created by trudbot on 2022/9/11.
//

#include <bits/stdc++.h>
using namespace std;

class HashString {
private:
    typedef unsigned long long ull;
    const int P = 131;
    vector<ull> p;
    vector<ull> prefix;
    int n;
public:
    HashString(string s) {
        n = s.size();
        s.insert(0, "0");
        p.resize(n + 1), p[0] = 1;
        prefix.resize(n + 1, 0);
        for(int i=1; i<=n; i++) {
            p[i] = p[i-1] * P;
            prefix[i] = prefix[i - 1] * P + s[i];
        }
    }

    ull get(int l, int r) {
        assert(l > 0 && r <= n && l <= r);
        return prefix[r] - prefix[l - 1] * p[r - l + 1];
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "cde";
    HashString hs1 = HashString(s1);
    HashString hs2 = HashString(s2);

    cout << hs1.get(3, 5) << endl;
    cout << hs2.get(1, 3) << endl;
}
