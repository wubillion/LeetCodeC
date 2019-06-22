#include <malloc.h>
#include <stddef.h>
//
// Created by wbl on 2017/8/16.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    //struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* result = cur;
    while (l1!=NULL && l2!=NULL)
    {
        if (l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        } else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    cur->next = l1==NULL? l2: l1;

    return result->next;
}