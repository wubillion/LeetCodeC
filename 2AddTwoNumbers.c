#include <malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * p = l1;
    struct ListNode * q = l2;
    struct ListNode * answer = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * head = answer;
    int extra = 0;
    while (p||q||extra)
    {
        int sum = (p ? p->val : 0) + (q ? q->val : 0) + extra;
        extra = sum / 10;
        answer->val = sum % 10;
        answer->next = NULL;

        p = p ? p->next : p;    //key step
        q = q ? q->next : q;    //key step

        if(p||q||extra)
        {
            answer->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            answer = answer->next;
        }
    }
    return head;
}