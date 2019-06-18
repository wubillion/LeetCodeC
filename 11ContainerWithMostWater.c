//
// Created by wbl on 2017/8/14.
// 水的容积由短高度决定的，分别以最左最右为桶壁，如果左侧A1小于右侧An，以A1为容器壁的最大体积为 A1*（n-1）；其余情况都不需考虑，此时移动左侧壁到A2，
// 如果A1>An，同理，移动An到A（n-1）.不断比较Ai和Aj，直到i==j.
// 总体思路类似于夹逼定理，记录最大的容器，


int maxArea(int* height, int heightSize) {

    int left = 0, right = heightSize - 1;
    int max = 0;
    int temp = 0;
    while (left!=right)
    {
        if(height[left]<=height[right])
        {
            temp = height[left]*(right-left);
            left++;
        } else
        {
            temp = height[right]*(right-left);
            right--;
        }
        if(max<temp)    { max = temp;   }
    }
    return max;
}