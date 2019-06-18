//
// Created by wbl on 2017/8/14.
//数字翻转，注意负数，注意反转之后越界，注意末尾是0;
//基本思路是不断mod10
//

#include <limits.h>

int reverse(int x) {
    const int MAX = INT_MAX;
    int flag = x > 0 ? 1 : -1;

    int temp = x * flag;
    int result = 0;

    while (temp!=0)
    {
        int integer = temp % 10;
        if(result > ((MAX-integer)/10))     //此处判断越界比较简洁
        {
            return 0;
        }

        result = result*10 + integer;

        temp = temp / 10;
    }

    return result*flag;
}