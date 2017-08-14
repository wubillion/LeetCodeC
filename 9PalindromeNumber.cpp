//
// Created by wbl on 2017/8/14.
// 判断整数是不是回文，并且空间复杂度O(1)

//



bool isPalindrome(int x) {

    int d = 1;
    if(x < 0)
    {
        return false;
    }

    while ( x / d >= 10)
    {
        d = d * 10;
    }

    while (x > 0)
    {
        int left = x / d;
        int right = x % 10;

        if(left!=right)
            return false;

        x = (x % d) / 10;
        d /= 100;
    }

    return true;
}

