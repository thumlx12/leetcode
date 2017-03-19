cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "3-LongestSubstringWithoutRepeatingCharacters.cpp" 4-MedianofTwoSortedArrays.cpp 5-LongestPalindromicSubstring.cpp)
add_executable(LeetCode ${SOURCE_FILES})