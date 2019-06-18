//
// Created by 203 on 2018/10/24.
//

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef  int _stdcall (*function)(int a, int b);

int mainn()
{
    HINSTANCE a = LoadLibrary("ConsoleApplication3.dll");

    function function1;

    int result = 0;
    if(a != NULL)
    {
        function1 = (function)GetProcAddress(a, "add");

        if(function1!=NULL)
        {
            result = function1(3,4);
            printf("%d\n",result);
        }
    }
    else
    {
        printf("Failed!");
    }

    FreeLibrary(a);

    return 0;
}
