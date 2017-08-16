//
// Created by wbl on 2017/8/15.
//

#include <malloc.h>
#include <limits.h>

int abs(int target){
    return target > 0? target: -target;
}

void qqSort(int* A, int begin, int end)
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

    qqSort(A, begin, left-1 );
    qqSort(A, left+1, end);
}

int threeSumClosest(int* nums, int numsSize, int target) {

    //快速排序
    qqSort(nums, 0, numsSize-1);

    int left = 0, right = 0;
    int sum = 0;
    int min = INT_MAX;

    for(int i = 0; i < numsSize-2; i++)
    {
        left = i + 1;
        right = numsSize - 1;

        while(left < right)
        {
            sum = nums[i] + nums[left] + nums[right];
            if(abs(min) >= abs(sum - target))
                min = sum - target;

            if(sum == target)
                return sum;
            else if(sum > target)
                right--;
            else
                left++;

        }

    }
    return min + target;

}