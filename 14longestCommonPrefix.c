//
// Created by wbl on 2017/8/14.
//
#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    if(strsSize == 0)
        return "";

    //注意此处strlen，如果str是空的，此时len会报运行时错误。因此判断条件加在最前。
    char* str = strs[0];
    int len = strlen(str);



    for(int column = 0; column < len; column++)
    {
        for (int row = 0; row < strsSize; row++)
        {
            if(str[column] != strs[row][column])
            {
                str[column] = '\0';
                return str;
            }
        }
    }
    return str;
}
