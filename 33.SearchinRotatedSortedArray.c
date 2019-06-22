//
// Created by 203 on 2019/6/17.
// 先确定截断处位置，再用两次二分查找.
//
#include <stdio.h>

int binarySearch(int *nums, int start, int stop, int target)
{
    int left = start, right = stop;
    int mid = (left + right) / 2;

    while(left <= right)
    {
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }

    return -1;
}

int findCut(int *nums, int numSize)
{
    int left = 0, right = numSize - 1;
    int mid = (left + right) / 2;

    while(left < right)
    {
        if(nums[left] < nums[mid])
        {
            left = mid;
        } else
        {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return left + 1;
}

int search(int* nums, int numsSize, int target)
{
    if(numsSize==0)
        return -1;

    int cutIndex = findCut(nums,numsSize);
    int result1 = binarySearch(nums,0,cutIndex-1,target);

    if(result1 != -1)
        return result1;

    int result2 = binarySearch(nums,cutIndex,numsSize-1,target);

    if(result2 != -1)
        return result2;

    return -1;
}