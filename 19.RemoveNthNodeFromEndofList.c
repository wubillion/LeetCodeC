//
// Created by wbl on 2017/8/16.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{

    if(head -> next == NULL)
        return NULL;
    struct ListNode* first = head;
    struct ListNode* second = head;

    for (int i = 0; i < n; ++i)
        second = second -> next;
    if (second == NULL)
        return head->next;

    while(second->next != NULL)
    {
        second = second->next;
        first = first->next;
    }
    first->next = first->next->next;
    return head;
}