//
// Created by wbl on 2017/8/21.
// 两种方法，第一种是暴力匹配，被称作Brute Force搜索，第二种是KMP算法，是最优的线性算法.
//
#include <string.h>
#include <stdio.h>
int strStr(char* haystack, char* needle) {

    int lenHay = strlen(haystack);
    int lenNeedle = strlen(needle);

    if(lenNeedle == 0)
        return 0;
    //int index = 0;
    for(int i = 0; i <= lenHay - lenNeedle; i++)
    {
        if(haystack[i] == needle[0])
        {
            int index = 0;
            while (index < lenNeedle)
            {
                if(haystack[i + index] != needle[index])
                {
                    break;
                }
                index++;
            }
            if(index == lenNeedle)
                return i;
        }
    }
    return -1;
}

