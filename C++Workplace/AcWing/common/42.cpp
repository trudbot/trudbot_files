//
// Created by trudbot on 2022/6/19.
//
/**
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。

假设压入栈的所有数字均不相等。

例如序列 1,2,3,4,5 是某栈的压入顺序，序列 4,5,3,2,1 是该压栈序列对应的一个弹出序列，但 4,3,5,1,2 就不可能是该压栈序列的弹出序列。

注意：若两个序列长度不等则视为并不是一个栈的压入、弹出序列。若两个序列都为空，则视为是一个栈的压入、弹出序列。

数据范围
序列长度 [0,1000]。

样例
输入：[1,2,3,4,5]
      [4,5,3,2,1]

输出：true

 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() ^ popV.empty() || pushV.size() != popV.size()){
            return false;
        }
        else if(pushV.empty() && popV.empty()){
            return true;
        }
        stack<int> s;
        auto j = popV.begin();
        for(auto i = pushV.begin(); i<pushV.end(); i++){
            s.push(*i);
            while(!s.empty() && s.top() == *j){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

int main() {
    vector<int> pushV{1,2,3,4,5};
    vector<int> popV{1, 5, 4, 3, 2};
    Solution solution;
    if(solution.isPopOrder(pushV, popV)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}
