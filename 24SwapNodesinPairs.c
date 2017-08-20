//
// Created by wbl on 2017/8/19.
//

#include <stdio.h>
#include <malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {

    if(head == NULL)
        return NULL;

    struct ListNode* pre, *cur;
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;
    pre = temp;
    cur = pre->next;

    while (cur != NULL && cur->next != NULL)
    {

        pre->next = cur->next;

        cur->next = cur->next->next;

        pre->next->next = cur;

        pre = cur;
        cur = cur->next;
    }

    return temp->next;
}