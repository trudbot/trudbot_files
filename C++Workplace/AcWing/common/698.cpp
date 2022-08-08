
//
// Created by trudbot on 2022/8/7.
//

#include <bits/stdc++.h>

#define pb push_back;
#define uset unordered_set
#define umap unordered_map
#define v vector
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

string read[] = {"", "single", " double", " triple", " quadruple", " quintuple",
                    " sextuple"," septuple", " octuple", " nonuple", " decuple"};
string number[] = {" zero", " one", " two", " three", " four", " five", " six",
                   " seven"," eight", " nine"};
int main() {
    FASTIO

    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        cout << "Case #" << t <<": ";
        string pn; cin >> pn;
        string rule; cin >> rule;
        int l = 0, r, i, j;
        for(int k=0; k<rule.length(); k++)
        {
            int len = 0;
            while(k < rule.length() && isdigit(rule[k])) len = len*10 + rule[k++] - '0';
            r = l + len;
            while(l < r)
            {
                int n = 0;
                for(i=l; i<r; i++)
                {
                    if(pn[i] == pn[l]) n++;
                    else break;
                }
                if(n == 1 || n >= 11)
                    while (n--) cout << number[pn[l] - '0'];
                else
                    cout << read[n] << number[pn[l] - '0'];
                l = i;
            }
        }
        cout << endl;
    }
    return 0;
}