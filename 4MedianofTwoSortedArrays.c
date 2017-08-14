//
// Created by wbl on 2017/8/14.
//

int min(int a, int b)
{
    return a <= b ? a: b;
}
int findKth(int* A, int m, int* B, int n, int k)
{
    if(m > n)                          //假设m比n小
        return findKth(B, n, A, m, k);
    if(m == 0)
        return *(B + k -1);
    if(k == 1)
        return min(*A, *B);

    int flagA = min(k / 2, m), flagB = k - flagA;

    if(*(A + flagA - 1) < *(B + flagB -1))
        return findKth(A + flagA, m - flagA, B, n, k - flagA);

    else if(*(A + flagA - 1) > *(B + flagB -1))
        return findKth(A, m , B + flagB, n - flagB, k - flagB);

    else
        return *(A + flagA - 1);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)     //int* 是数组首地址
{
    int total = nums1Size + nums2Size;  //数组总个数
    int x = 0, y = 0;
    if(total & 0x1)                     //与运算，奇数；1&1 = 1，0&1 = 0
        return findKth(nums1, nums1Size, nums2, nums2Size, total/2 + 1);
    else
    {
        x = findKth(nums1, nums1Size, nums2, nums2Size, total/2);
        y = findKth(nums1, nums1Size, nums2, nums2Size, total/2 + 1);

        return (x + y) / 2.0;
    }
}
