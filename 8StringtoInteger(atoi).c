//
// Created by wbl on 2017/8/14.
// 字符串转int，但是很刁钻，要求很多
// 多余空格去除、无效格式去除，比如++1，返回0
// 溢出数据，返回最大的值，
// 不规则输入，第一个字符之前判定，比如-22a,返回-22
//

#include <stdlib.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* str) {

    int len = strlen(str);
    int index = 0;
    int flag = 1;
    int result = 0;

    while (str[index] == '' && index<len)   { index++;  }

    if(str[index] == '+')   { index++;  }
    else if(str[index] == '-')
    {
        flag = -1;
        index++;
    }

    while (index < len)
    {

        if(str[index] < '0' || str[index] > '9')
            break;
        int temp = str[index] - '0';
        if(result > ((INT_MAX-temp)/10))
        {
            return flag == -1?INT_MIN:INT_MAX;
        }
        result = result*10 + temp;
        index++;
    }
    return result*flag;
}
