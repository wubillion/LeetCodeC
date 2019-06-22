#include <malloc.h>
#include <stddef.h>
//
// Created by wbl on 2017/8/19.
// 这一题坑了我两天，原因就在于reverse，反转函数这里，如果用头插法，那么头尾指针就会改变，如果用原地插入法，则可以避免很多问题
//
struct ListNode
{
    int val;
    struct ListNode *next;
};

//将一个链表反转

void reverseByHead(struct ListNode** head, struct ListNode** tail) {
    struct ListNode *pre, *cur, *end;
    pre = NULL;
    cur = *head;
    end = *head;


    while (cur != (*tail)->next)
    {
        struct ListNode* next = cur->next;
        cur->next = pre;
        *head = cur;
        pre = cur;
        cur = next;
    }
    return;
}

void reverseList(struct ListNode** head, struct ListNode** tail)
{
    struct ListNode *dummy, *pre, *cur, *flag;
    //struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy = (*head);

    pre = dummy->next;
    cur = pre->next;

    if((*tail) != NULL)
        flag = (*tail)->next;
    else
        flag = NULL;

    while (cur != flag)
    {
        pre->next = cur->next;
        cur->next = dummy->next;
        dummy->next = cur;

        cur = pre->next;
    }
    *head = pre;
    *tail = pre;
    return;
}




struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode *left, *right;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    left = dummy;
    right = head;
    int index = 1;

    while(right != NULL)
    {
        right = right->next;
        index++;

        if(index % k == 0 && right != NULL)
        {
            //struct ListNode* next = right->next;
            reverseList(&left,&right);
            //left = next;
            //right = next;
        }
    }
    return dummy->next;

}