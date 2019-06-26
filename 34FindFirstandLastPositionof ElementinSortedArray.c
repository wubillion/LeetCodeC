//
// Created by wbl on 2019/6/18.
//
#include <limits.h>
#include <stdio.h>
#include <malloc.h>

int binaryLeftSearch(int* num, int numSize, int target)
{
    if(numSize == 0)
        return -1;
    int left = 0, right = numSize - 1;
    int mid = (left + right) / 2;
    int result = -1;
    while (left < right)
    {
        if(num[mid] < target)
        {
            left = mid + 1;
        }
        else if(num[mid] > target)
        {
            right = mid - 1;
        }
        else if(num[mid] == target)
        {
            right = mid;
        }
        mid = (left + right) / 2;
    }

    if(num[left]==target)
        result = left;

    return result;
}

int binaryRightSearch(int* num, int numSize, int target)
{
    if(numSize == 0)
        return -1;
    int left = 0, right = numSize - 1;
    int mid = (left + right) / 2 + 1;   //防止数组越界
    int result = -1;
    while (left < right)
    {
        if(num[mid] < target)
        {
            left = mid + 1;
        }
        else if(num[mid] > target)
        {
            right = mid - 1;
        }
        else if(num[mid] == target)
        {
            left = mid;
        }
        mid = (left + right) / 2 + 1;
    }

    if(num[right] == target)
        result = right;

    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{

    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int)*2);

    result[0] = binaryLeftSearch(nums, numsSize, target);
    result[1] = binaryRightSearch(nums, numsSize, target);

    return result;
}


