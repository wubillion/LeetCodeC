#include <stdio.h>
#include <windows.h>
char *returnStr()
{
    char* p= (char *) "Hello World!";
    return p;
}
int mahin()
{

    HINSTANCE ab = LoadLibrary("a.dll");
    char *str=NULL;//一定要初始化，好习惯
    str=returnStr();
    printf("%s\n", str);
    return 0;
}
