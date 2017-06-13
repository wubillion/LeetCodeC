//
// Created by wbl on 2017/4/26.
//
#include <stdio.h>




double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int total = nums1Size + nums2Size;  //数组总个数
    int flag = 0;                       //比中位数小的个数
    if(total%2 == 0)
        flag = total / 2;
    else
        flag = (total-1) / 2;


}
