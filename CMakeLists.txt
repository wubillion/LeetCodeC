cmake_minimum_required(VERSION 3.6)
project(LeetCodeC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES 2AddTwoNumbers.c 3LengthOfLongestSubstring.c 4FindMedianSortedArrays.c 5LongestPalindromicSubstring.cpp "6ZigZag Conversion.c" 7ReverseInteger.c "8StringtoInteger(atoi).c" 9PalindromeNumber.cpp)
add_executable(LeetCodeC ${SOURCE_FILES})