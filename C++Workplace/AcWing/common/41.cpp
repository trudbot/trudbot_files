
//
// Created by trudbot on 2022/8/5.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

class MinStack {
public:
    /** initialize your dat structure here. */
    int minVal[110];
    int data[110];
    int tail;

    MinStack() {
        tail = 1;
        minVal[0] = 1e9;
    }

    void push(int x) {
        data[tail] = x;
        minVal[tail] = min(minVal[tail-1], x);
        tail++;
    }

    void pop() {
        tail--;
    }

    int top() {
        return data[tail-1];
    }

    int getMin() {
        return minVal[tail-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}