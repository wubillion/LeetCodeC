//
// Created by wbl on 2017/8/21.
//

int removeElement(int* nums, int numsSize, int val)
{
    int write = 0, read = 0;

    while (read < numsSize)
    {
        if(nums[read] != val)
        {
            nums[write] = nums[read];
            write++;
        }
        read++;
    }
    return write;
}