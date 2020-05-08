#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        int i      = 1;
        int pos    = length - n + 1;
        ListNode* p;
        ListNode* pre = head;

        if (pos == 1) {
            p    = head;
            head = head->next;
        } else {
            while (pre->next != NULL) {
                i++;
                if (i == pos) {
                    p         = pre->next;
                    pre->next = p->next;
                    return head;
                }
                pre = pre->next;
            }
        }
        return head;
    }

    int getLength(ListNode* node) {
        int length = 0;
        while (node != NULL) {
            length++;
            node = node->next;
        }
        return length;
    }
};