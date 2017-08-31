cmake_minimum_required(VERSION 3.6)
project(LeetCodeC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES 2AddTwoNumbers.c 3LengthOfLongestSubstring.c 4MedianofTwoSortedArrays.c 5LongestPalindromicSubstring.c "6ZigZag Conversion.c" 7ReverseInteger.c "8StringtoInteger(atoi).c" 9PalindromeNumber.c 4MedianofTwoSortedArrays.c 11ContainerWithMostWater.c 12IntegertoRoman.c 13RomantoInteger.c 14longestCommonPrefix.c 15ThreeSum.c 16ThreeSumClosest.c 18FourSum.c 17LetterCombinationsofaPhoneNumber.c 19.RemoveNthNodeFromEndofList.c 20ValidParentheses.c 21MergeTwoSortedLists.c 22GenerateParentheses.c 23MergekSortedLists.c 24SwapNodesinPairs.c 25ReverseNodesink-Group.c 26RemoveDuplicatesfromSortedArray.c 27RemoveElement.c 28ImplementstrStr.c Test.cpp)
add_executable(LeetCodeC ${SOURCE_FILES})