
//
// Created by trudbot on 2022/8/2.
//

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    typedef ListNode* ln;

    struct cmp {
        bool operator() (const ln& a, const ln& b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
            for(ln & i : lists) {
                if(i) {
                    heap.push(i);
                }
            }
            ln head = new ListNode(), curr = head;
            while(!heap.empty()) {
                curr->next = heap.top();
                heap.pop();
                curr =  curr->next;
                if(curr->next) {
                    heap.push(curr->next);
                }
            }

            return head->next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}