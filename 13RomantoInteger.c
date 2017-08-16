//
// Created by wbl on 2017/8/14.
//

#include <string.h>

int changeToInt(char Roman)
{
    switch (Roman)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}


int romanToInt(char* s) {

    const int len = strlen(s);
    int result = 0;

    int before = 0, after = 0;
    for (int i=0; i<len-1; i++)
    {
        before = changeToInt(s[i]);
        after = changeToInt(s[i+1]);
        if(before < after)
        {
            result -= before;
        } else
        {
            result += before;
        }
    }
    result += changeToInt(s[len-1]);
    return result;
}