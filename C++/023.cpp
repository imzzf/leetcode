#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //分治算法
        //各链表两两一组进行合并
        if (lists.empty()) {
            return NULL;
        }
        int interval = 1;  //初始化间隔
        while (interval < lists.size()) {
            for (int i = 0; i < lists.size() - interval; i = i + interval * 2) {
                //第一轮合并(0,1),(2,3),...间隔为1
                //剩余0,2,4,6,...
                //第二轮合并(0,2),(4,6),...间隔为1*2
                //...
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

    //参考21-合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p   = new ListNode(0);
        ListNode* tmp = p;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1        = l1->next;
            } else {
                tmp->next = l2;
                l2        = l2->next;
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