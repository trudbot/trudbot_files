//
// Created by trudbot on 2022/7/5.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;

int N;
unordered_map<double, map<int, int>> ht;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x, y, p, score = 0, step = 0;
    cin >> N;
    while(N--)
    {
        cin >> x >> y >> p;
        ht[1.0*y/x][x] = p;
    }

    for(const auto& i : ht)
    {
        map<int, int> curr = i.second;
        bool flag = false;
        for(auto j : curr)
        {
            if(j.second > 1)
            {
                flag = false;
                step++;
                score += j.second;
            }
            else if(!flag)
            {
                flag = true;
                step++;
                score++;
            }
            else score++;
        }
    }
    cout << score << " " << step;
    return 0;
}
