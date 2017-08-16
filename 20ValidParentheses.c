//
// Created by wbl on 2017/8/16.
//

#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

bool cmp(char left, char right)
{
    bool flag = false;
    if(left == '#')
        flag = false;
    else if(left == '(' && right == ')')
        flag = true;
    else if(left == '[' && right == ']')
        flag = true;
    else if(left == '{' && right == '}')
        flag = true;

    return flag;
}


bool isValid(char* s) {
    bool flag = false;
    const int len = strlen(s);

    char* stack = (char*)malloc(sizeof(char)*(len+1));
    stack[0] = '#';
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (cmp(stack[index],s[i]))
            index--;
        else
            stack[++index] = s[i];

    }

    if(stack[index] == '#')
        flag = true;
    else
        flag = false;

    return flag;
}

int main()
{
    bool ff = isValid("()");
    if(ff)
        printf("XXX");
    else
        printf("YYY");
}