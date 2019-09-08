#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        ListNode* tmp = p;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1      = l1->next;
            } else {
                tmp->next = l2;
                l2      = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1 == NULL) {
            tmp->next = l2;
        } else {
            tmp->next = l1;
        }
        return p->next;
    }
};

int main() {
    return 0;
}