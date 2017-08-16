//
// Created by wbl on 2017/8/15.
//

#include <stdio.h>
#include <malloc.h>

void swap(int* A, int left, int right)
{
    int temp = A[left];
    A[left] = A[right];
    A[right] = temp;
    return;
}

//快速排序解法一
void quickSort(int* A, int begin, int end)
{
    if(begin > end)
        return;

    int flag = A[end];
    int left = begin;

    for (int right = begin; right <= end; right++)
    {
        if(A[right] < flag)
        {
            swap(A,left,right);
            left++;
        }
    }

    swap(A,left,end);

    quickSort(A,begin,left-1);
    quickSort(A,left+1,end);
}

//快速排序解法二
void qSort(int* A, int begin, int end)
{
    if(begin >= end)
        return;

    int flag = A[begin];
    int left = begin, right = end;

    while(left < right)
    {
        while (left < right && A[right] >= flag)
            right--;
        A[left] = A[right];

        while (left < right && A[left] <= flag)
            left++;
        A[right] = A[left];
    }
    A[left] = flag;

    qSort(A, begin, left-1 );
    qSort(A, left+1, end);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {

    //定义一个二位数组，空间大小为可能出现所有的三元组指针所占的空间，最大元组个数为 n*(n-1)*(n-2)/6,但是这种赋值方法会使数组越界，所以简单粗暴，直接1000000；
    //int** result = (int**)malloc(sizeof(int*)*((numsSize/2+1)*((numsSize-1)*(numsSize-2)/3+1)));
    int** result = (int**)malloc(sizeof(int*)*1000000);
    if(numsSize <3)
    {
        *returnSize = 0;
        return result;
    }
    //快速排序
    //qSort(nums, 0, numsSize-1);
    quickSort(nums, 0, numsSize-1);
    int left = 0, right = 0;
    int sum = 0;
    int top = 0;

    for(int i = 0; i < numsSize-2; i++)
    {
        if(nums[i] > 0)
            break;

        if(i > 0 && nums[i]==nums[i-1])
            continue;

        left = i+1;
        right = numsSize-1;

        while(left < right)
        {
            sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result[top] = (int*)malloc(sizeof(int)*3);
                result[top][0] = nums[i];
                result[top][1] = nums[left];
                result[top][2] = nums[right];

                //继续寻找下一对.
                left++;
                right--;
                top++;

                while(left < right && nums[right] == nums[right+1])
                    right--;

                while(left < right && nums[left] == nums[left-1])
                    left++;

            } else if(sum > 0)
                right--;
            else if(sum < 0)
                left++;
        }

    }
    *returnSize = top;
    return result;
}

