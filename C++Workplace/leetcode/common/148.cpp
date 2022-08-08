
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
    typedef ListNode* ltp;
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ltp l1, l2;
        l1 = l2 = head;
        while(l2->next && l2->next->next) {
            l2 = l2->next->next;
            l1 = l1->next;
        }
        l2 = l1->next;
        l1->next = nullptr;
        l1 = sortList(head);
        l2 = sortList(l2);

        ltp h = new ListNode(), curr = h;
        while(l1 && l2)
        {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1) {
            curr->next = l1;
        }
        if(l2) {
            curr->next = l2;
        }
        curr = h->next;
        return curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}