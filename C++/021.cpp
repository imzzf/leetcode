#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev  = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1         = l1->next;
            } else {
                prev->next = l2;
                l2         = l2->next;
            }
            prev = prev->next;
        }
        if (l1 == NULL)
            prev->next = l2;
        else
            prev->next = l1;
        return dummy->next;
    }
};

int main() {
    return 0;
}