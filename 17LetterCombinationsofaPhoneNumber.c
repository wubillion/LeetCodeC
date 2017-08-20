//
// Created by wbl on 2017/8/15.
//

#include <malloc.h>
#include <string.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int *returnSize) {

    const int dightLen = strlen(digits);

    char** result = (char**)malloc(sizeof(char*));
    result[0] = "";
    int top = 1;
    int index = 0;
    int symbolLen = 0;
    char* symbol[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (int i = 0; i < dightLen; i++)
    {
        symbolLen = strlen(symbol[digits[i]-'0']);
        char** level = (char**)malloc(sizeof(char*)*(top*symbolLen));

        index = 0;
        for(int j = 0; j < symbolLen; j++)
        {

            for (int k = 0; k < top; k++)
            {
                char* temp = (char*)malloc(sizeof(char)*(i+2));
                char c = symbol[digits[i]-'0'][j];

                strcpy(temp,result[k]);
                temp[i] = c;
                temp[i+1] = '\0';
                level[index] = temp;
                index ++;

            }
        }
        result = level;
        *returnSize = index;
        top *= symbolLen;
    }

    return result;
}
