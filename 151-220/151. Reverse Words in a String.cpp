//
// Created by maolixuan on 2017/5/28.
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
#include <queue>

using namespace std;

class Solution151 {
public:

    void trimStr(string &s) {
        int l = 0;
        int r = s.length() - 1;
        while (s[l] == ' ') {
            ++l;
        }
        while (s[r] == ' ') {
            --r;
        }
        if (l > r) {
            s = "";
            return;
        } else {
            s = s.substr(l, r - l + 1);
        }
        string singleSpace = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                singleSpace.push_back(s[i]);
            } else {
                if (s[i - 1] != ' ') {
                    singleSpace.push_back(' ');
                }
            }
        }
        s = singleSpace;
    }

    void reverseWords(string &s) {
        trimStr(s);
        if (s.length() < 3) {
            return;
        }
        int leftStart = 0;
        int rightEnd = s.length() - 1;
        int ltPoint = 0;
        int rtPoint = s.length() - 1;
        string leftWord = "", rightWord = "";
        bool hasLW = false;
        bool hasRW = false;
        for (; ltPoint <= rtPoint;) {
            if (s[ltPoint] != ' ') {
                ++ltPoint;
            } else {
                if (!hasLW) {
                    leftWord = s.substr(leftStart, ltPoint - leftStart);
                    hasLW = true;
                }
            }
            if (s[rtPoint] != ' ') {
                --rtPoint;
            } else {
                if (!hasRW) {
                    rightWord = s.substr(rtPoint + 1, rightEnd - rtPoint);
                    hasRW = true;
                }
            }
            if (hasLW && hasRW) {
                string leftPart = (leftStart - 1 < 0) ? "" : s.substr(0, leftStart);
                string rightPart = (rightEnd + 1 >= s.length()) ? "" : s.substr(rightEnd + 1, s.length() - rightEnd);
                string middlePart = s.substr(ltPoint, rtPoint - ltPoint + 1);
                s = leftPart + rightWord + middlePart + leftWord + rightPart;
                hasLW = false;
                hasRW = false;
                ltPoint = leftStart + rightWord.length() + 1;
                rtPoint = rightEnd - leftWord.length() - 1;
                leftStart = ltPoint;
                rightEnd = rtPoint;
            }
        }
    }

    void reverseWords_simple(string &s) {
        trimStr(s);
        if (s.length() <= 2) {
            return;
        }
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());
        reverse(s.begin(), s.end());
    }
};

//
//int main() {
//    string s1 = "   one.   +two three?   ~four   !five- ";
//    string s2 = "hello world!";
//    Solution151 *solu;
//    solu->reverseWords_simple(s1);
//    solu->reverseWords_simple(s2);
//    string s3 = "abcdef";
//    reverse(s3.begin() + 2, s3.end());
//    cout << s1 << endl << s2 << endl << s3;
//}