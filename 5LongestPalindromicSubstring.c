//
// Created by wbl on 2017/6/24.
// 动态规划问题
//
#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    char result[1001];
    int length = strlen(s);
    bool f[length][length];
    memset(f, false, sizeof(f));
    int maxLength = 1;
    int startPoint = 0;

    for(int i = 0; i < length; i++)
    {
        f[i][i] = true;
        if(i<length-1 && s[i]==s[i+1])
        {
            f[i][i+1] = true;
            maxLength = 2;
            startPoint = i;
        }
    }

    for(int l = 2; l < length; l++)         //l是步长
    {
        for(int k = 0; k < length - l; k++)
        {
            f[k][k+l] = (f[k+1][k+l-1] && s[k]==s[k+l]);
            if(f[k][k+l] == true && maxLength <= (l + 1))
            {
                maxLength = l + 1;
                startPoint = k;
            }
        }
    }
    return strncpy(result, s+startPoint, maxLength);
}

