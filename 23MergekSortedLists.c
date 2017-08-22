//
// Created by wbl on 2017/8/18.
//
// 堆排序（小顶堆），外部排序，多路归并排序.
// 主要复杂性在于建堆和更新堆的操作.
// 堆是一个完全二叉树，对于节点i来说，其父亲节点为 i/2
// 左孩子节点为2*i，右孩子节点为2*i+1;
//
#include <malloc.h>
#include <limits.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};



//将当前值调节入
void adjustTree(struct ListNode** lists, int listSize, int index)
{
    if(index > (listSize-1) / 2)
        return;

    int resultIndex = 0;
    int leftIndex = index * 2 + 1;
    int rightIndex = index * 2 + 2;

    int indexValue = lists[index]->val;
    int leftValue = lists[leftIndex]->val;
    int rightValue = (rightIndex) >= listSize ? INT_MAX : lists[rightIndex]->val;

    if(leftValue <= rightValue)
    {
        //此时进行交换
        if(indexValue > leftValue)
        {
            struct ListNode* temp = lists[index];
            lists[index] = lists[leftIndex];
            lists[leftIndex] = temp;
            resultIndex = leftIndex;
        }

    } else
    {
        if(indexValue > rightValue)
        {
            struct ListNode* temp = lists[index];
            lists[index] = lists[rightIndex];
            lists[rightIndex] = temp;
            resultIndex = rightIndex;
        }
    }
    adjustTree(lists,listSize,resultIndex);
}


//建立小顶堆的过程
void buildTree(struct ListNode** lists, int listSize)
{
    //建树的过程要从下标 (n-1)/2 处开始
    int begin = (listSize-1) / 2;
    for(int index = begin; index >= 0; index--)
        adjustTree(lists, listSize, index);

}


//此处理解lists应该认为是所有的list的头的合集
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));

    if(listsSize == 0)
        return NULL;
    //以k个头结点建立小顶堆
    buildTree(lists, listsSize);


    head->next = lists[0];
    struct ListNode* cur = head->next;
    lists[0] = lists[0]->next;
    int index = 0;

    while (lists[0] != NULL)
    {
        cur->next = lists[0];
        lists[0] = lists[0]->next;
        adjustTree(lists,listsSize,0);
    }

    return head->next;


}