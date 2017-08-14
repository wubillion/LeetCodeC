#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int length = strlen(s);
    int maxLength = 0;  //最大长度
    int current = 0;    //当前字串的起始下标
    int currentLength = 1; //当前字串长度
    for (int i = 0; i < length; i++)
    {
        for(int j = i - 1; j >= current; j--)
        {
            if(s[j] == s[i])
            {
                current = j + 1;
                currentLength = i - j;
                break;
            } else if(j == current)
            {
                currentLength++;
            }
        }
        if(currentLength > maxLength)
            maxLength = currentLength;
    }
    return maxLength;
}

