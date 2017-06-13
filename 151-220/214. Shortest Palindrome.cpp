//
// Created by sensetime on 6/10/17.
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
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <bitset>

using namespace std;

class Solution214 {
public:

    int longestPalindromePrefix(string s, int end) {
        int j = 0;
        for (int i = end - 1; 0 <= i; --i) {
            if (s[i] == s[j]) {
                ++j;
            }
        }
        if (j == end) {
            return end;
        } else {
            return longestPalindromePrefix(s, j);
        }
    }

    int *makeNext(string P) {
        int m = P.length();
        int j = 0;
        int *N = new int[m];
        int t = N[0] = -1;
        while (j < m - 1) {
            if (0 > t || P[j] == P[t]) {
                j++;
                t++;
                N[j] = (P[j] == P[t]) ? N[t] : t;
            } else {
                t = N[t];
            }
        }
        return N;
    }

    int longestPalindromePrefix(string s) {
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        int *next = makeNext(s);
        int mark = 0;
        for (int i = 0, j = 0; i < reverse_s.length();) {
            if (j < 0 || reverse_s[i] == s[j]) {
                ++i;
                ++j;
                if (i == reverse_s.length()) {
                    mark = j;
                }
            } else {
                j = next[j];
            }
        }
        return mark;
    }

    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        int longestPre1 = longestPalindromePrefix(s);
        string addPart = s.substr(longestPre1);
        reverse(addPart.begin(), addPart.end());
        return addPart + s;
    }

};

//int main() {
//    string str = "abbacd";
//    Solution214 *solu;
//    cout << solu->shortestPalindrome(str);
//}