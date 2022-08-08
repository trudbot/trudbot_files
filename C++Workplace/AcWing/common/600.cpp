//
// Created by trudbot on 2022/7/4.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int, int> PII;
int cows[100010];
int res[100010];
int sta[100010];
int top = -1;

void push(int i)
{
    while(top >= 0 && cows[sta[top]] < cows[i])
        res[sta[top--]] = i;
    sta[++top] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> cows[i];
    for(int i=1; i<=N; i++)
        push(i);
    while(top >= 0)
        res[sta[top--]] = 0;
    for(int i=1; i<=N; i++)
        cout << res[i] << endl;
    return 0;
}
