//
// Created by wbl on 2017/8/21.
//

int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;

    int slow = 1, fast = 1;

    while (fast < numsSize)
    {

        if(nums[fast-1] != nums[fast])
        {
            slow ++;
            nums[slow-1] = nums[fast];
        }
        fast++;
    }
    return slow;
}