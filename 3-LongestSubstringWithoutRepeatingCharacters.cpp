//
// Created by jackie on 3/19/17.
//
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.size() <= 1) {
        return s.size();
    }
    int left = -1;
    int *lastOccured = new int[256];
    int maxLength = 0;
    memset(lastOccured, -1, sizeof lastOccured);

    for (int i = 0; i < s.size(); ++i) {
        if (left <= lastOccured[s[i]]) {
            left = lastOccured[s[i]] + 1;
        }
        lastOccured[s[i]] = i;
        if (maxLength < (i - left + 1)) {
            maxLength = i - left + 1;
        }
    }
    return maxLength;
}