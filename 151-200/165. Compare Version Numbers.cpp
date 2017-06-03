//
// Created by sensetime on 6/2/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution165 {
public:
    int compareVersion(string version1, string version2) {
        version1.push_back('.');
        version2.push_back('.');
        int num1 = 0;
        int num2 = 0;
        bool getFirst = false;
        bool getSecond = false;
        int i = 0, j = 0;
        for (; i < version1.length() && j < version2.length();) {
            if (version1[i] == '.') {
                getFirst = true;
            } else {
                num1 = num1 * 10 + (version1[i] - 48);
                ++i;
            }
            if (version2[j] == '.') {
                getSecond = true;
            } else {
                num2 = num2 * 10 + (version2[j] - 48);
                ++j;
            }
            if (getFirst && getSecond) {
                if (num1 > num2) {
                    return 1;
                }
                if (num1 < num2) {
                    return -1;
                }
                num1 = 0;
                num2 = 0;
                getFirst = false;
                getSecond = false;
                ++i;
                ++j;
            }
        }
        if (j < version2.length()) {
            num2 = 0;
            getSecond = false;
            for (int t = j; t < version2.length(); ++t) {
                if (version2[t] == '.') {
                    if (num2 > 0) {
                        return -1;
                    }
                    num2 = 0;
                    getSecond = false;
                } else {
                    num2 = num2 * 10 + (version2[t] - 48);
                }
            }
        } else if (i < version1.length()) {
            num1 = 0;
            getFirst = false;
            for (int t = i; t < version1.length(); ++t) {
                if (version1[t] == '.') {
                    if (num1 > 0) {
                        return 1;
                    }
                    num1 = 0;
                    getFirst = false;
                } else {
                    num1 = num1 * 10 + (version1[t] - 48);
                }
            }
        }
        return 0;
    }
};