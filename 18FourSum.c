//
// Created by wbl on 2017/8/15.
//

#include <malloc.h>


void qquickSort(int* A, int begin, int end)
{
    if(begin >= end)
        return;

    int left = begin, right = end;
    int flag = A[left];

    while (left < right)
    {
        while (left < right && A[right] >= flag)
            right--;
        A[left] = A[right];

        while (left < right && A[left] <= flag)
            left++;
        A[right] = A[left];
    }

    A[left] = flag;

    qquickSort(A, begin, left-1);
    qquickSort(A, left+1, end);
}


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {

    int** result = (int**)malloc(sizeof(int*)*10000000);

    if(numsSize <4)
    {
        *returnSize = 0;
        return result;
    }

    qquickSort(nums, 0, numsSize - 1);

    int top = 0;
    int sum = 0;
    int left = 0, right = 0;
    for(int i = 0; i < numsSize - 3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        for(int j = i+1; j < numsSize - 2; j++)
        {
            if( j > i+1 && nums[j] == nums[j-1])
                continue;

            left = j+1;
            right = numsSize - 1;
            while (left < right)
            {
                sum = nums[left] + nums[right] + nums[i] + nums[j];
                if(sum == target)
                {
                    result[top] = (int*)malloc(sizeof(int)*4);

                    result[top][0] = nums[i];
                    result[top][1] = nums[j];
                    result[top][2] = nums[left];
                    result[top][3] = nums[right];

                    left++;
                    right--;
                    top++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                } else if(sum > target)
                {
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else
                {
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
            }

        }

    }

    *returnSize = top;
    return result;
}
