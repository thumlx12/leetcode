cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "3-LongestSubstringWithoutRepeatingCharacters.cpp" 4-MedianofTwoSortedArrays.cpp 5-LongestPalindromicSubstring.cpp 6-ZigzagConversion.cpp "7-ReverseInteger.cpp" "8-StringtoInteger(atoi).cpp" 10-RegularExpressionMatching.cpp local_test.cpp 11-ContainerWithMostWater.cpp 12-Integer2Roman.cpp 15-3Sum.cpp 16-3SumClosest.cpp 17-LetterCombinationsofaPhoneNumber.cpp "19. Remove Nth Node From End of List.cpp" "22. Generate Parentheses.cpp" "23. Merge k Sorted Lists.cpp" "24. Swap Nodes in Pairs.cpp" "25. Reverse Nodes in k-Group.cpp")
add_executable(LeetCode ${SOURCE_FILES})