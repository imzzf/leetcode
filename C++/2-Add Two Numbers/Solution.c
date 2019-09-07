/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* r = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = r;
    r->next=NULL;
    r->val=0;
    int t = 0;
    while(l1!=NULL||l2!=NULL)
    {
        int a=((l1!=NULL)?l1->val:0);
        int b=((l2!=NULL)?l2->val:0);
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        int sum = a + b + t;
        p->val = sum % 10;
        t = sum/10;
        tail->next=p;
        tail=p;
        if(l1!=NULL)
            l1=l1->next;
        if(l2!=NULL)
            l2=l2->next;
    }
    if(t!=0)
    {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = t;
        tail->next=p;
        tail=p;
    }
    tail->next=NULL;
    return r->next;
}
