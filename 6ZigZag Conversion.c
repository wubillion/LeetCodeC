//
// Created by wbl on 2017/8/13.
//数学解法比直接画图来的简便很多
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if(len==0 || numRows<2)
        return s;

    char *result = (char*)malloc(sizeof(char)*(len+1));
    char *output = result;
    result[len] = '\0';

    int lag = 2 * (numRows - 1);

    for(int i = 0; i < numRows; i++)
    {
        for(int index = i; index < len; index +=lag )
        {
            *result++ = s[index];

            if(i > 0 && i < numRows - 1)
            {
                int delta = index + lag - 2*i;
                if(delta < len)
                {
                    *result++ = s[delta];
                }
            }
        }
    }
    return output;
}

