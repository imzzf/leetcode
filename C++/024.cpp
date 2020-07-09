#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next     = head;
        ListNode* prev  = dummy;
        while (head != NULL && head->next != NULL) {
            ListNode* first  = head;
            ListNode* second = head->next;

            prev->next   = second;
            first->next  = second->next;
            second->next = first;

            prev = first;
            head = first->next;
        }
        return dummy->next;
    }
};

int main() {
    return 0;
}