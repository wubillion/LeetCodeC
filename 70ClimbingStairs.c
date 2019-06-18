//
// Created by 203 on 2019/5/5.
//

int climbStairs(int n)
{
    if(n<3)
       return n;

    int result[n+1];

    for (int j = 0; j < 3; ++j)
    {
        result[j]=j;
    }

    for (int i = 3; i <= n; ++i)
    {
        result[i]=result[i-1]+result[i-2];
    }

    return result[n];
}