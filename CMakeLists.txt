cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "3-LongestSubstringWithoutRepeatingCharacters.cpp" 4-MedianofTwoSortedArrays.cpp 5-LongestPalindromicSubstring.cpp 6-ZigzagConversion.cpp "7-ReverseInteger.cpp" "8-StringtoInteger(atoi).cpp" 10-RegularExpressionMatching.cpp local_test.cpp)
add_executable(LeetCode ${SOURCE_FILES})