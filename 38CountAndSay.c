//
// Created by wbl on 2019/6/23.
// 迭代或者递归,递归很慢，占用了很大的内存空间，反复调用
//
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

char * countAndSay(int n)
{
    if(n==1)
        return "1";

    char* temp = countAndSay(n-1);
    int len = strlen(temp);

    char* result = (char*)malloc(sizeof(char)*10240);
    result[0]='\0';
    char flag = temp[0];
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if(temp[i]!=flag)
        {
            sprintf(result,"%s%d%c",result,count,flag);
            flag = temp[i];
            count = 0;
        }
        count++;
    }

    sprintf(result,"%s%d%c",result,count,flag);
    return result;
}

int main()
{
    printf("%s\n",countAndSay(5));
}
