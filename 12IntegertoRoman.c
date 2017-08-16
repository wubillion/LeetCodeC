//
// Created by wbl on 2017/8/14.
//

#include <malloc.h>
#include <string.h>

char* intToRoman(int num) {

    char* symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[] =    {1000,900,500,400, 100, 90,  50, 40,  10,  9,  5,   4,  1};
    char* result = (char*)malloc(sizeof(char)*20);
    int index =0;
    for(int i=0; num!=0; i++)
    {
        while(num>=value[i])
        {
            num -= value[i];
            strcat(result,symbol[i]);
        }
    }
    strcat(result,"\0");
    return result;
}
