//
// Created by wbl on 2017/8/17.
//

#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void insert(char** result, char* temp, int* returnSize, int left, int right, int index)
{
    if(left == 0 && right == 0)
    {
        temp[index] = '\0';
        result[*returnSize] = (char*)malloc(sizeof(char) * (index));
        strcpy(result[*returnSize],temp);
        (*returnSize)++;
        return;
    }
    if(left > 0)
    {
        temp[index] = '(';
        insert(result, temp, returnSize, left-1, right, index+1);
    }
    if(right > 0 && left < right)
    {
        temp[index] = ')';
        insert(result, temp, returnSize, left, right-1, index+1);
    }
}


char** generateParenthesis(int n, int* returnSize)
{

    //所有排列的组合共有C(2n,n)/(n+1)种，成为卡塔兰数.
    char** result = (char**)malloc(sizeof(char*) * 1000000);
    char* temp = (char*)malloc(sizeof(char) * (n+1));
    *returnSize = 0;
    int left = n, right = n;
    int index = 0;

    insert(result, temp, returnSize, left, right, index);

    return result;
}
