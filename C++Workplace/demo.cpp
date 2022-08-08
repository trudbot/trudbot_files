#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool verifySequenceOfBST(vector<int> sequence) {
        return judge(sequence, 0, sequence.size()-1);
    }

    bool judge(vector<int> &a, int l, int r)
    {
        if(l >= r) return true;
        int mid = l;
        while(mid < r && a[mid] < a[r]) mid++;
        for(int i=mid; i<r; i++)
            if(a[i] < a[r]) return false;
        return judge(a, l, mid-1) && judge(a, mid, r-1);
    }
};

int main() {
    Solution s;
    vector<int> data{1, 2, 5, 4, 9, 10, 7, 3, 6, 8};
    cout << s.verifySequenceOfBST(data);
    return 0;
}

