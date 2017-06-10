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

    vector<int> makeNext(string &s) {
        vector<int> next;
        next.push_back(-1);
        for (int i = 0, j = -1; i < s.length();) {
            if (j == -1 || s[i] == s[j]) {
                j++;
                next.push_back(next[j] + 1);
                i++;
            } else {
                j = next[j];
            }
        }
        return next;
    }

    int longestPalindromePrefix(string s) {
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        vector<int> next = makeNext(s);
        for (int i = 0, j = 0; i < reverse_s.length();) {
            if (j == -1 || reverse_s[i] == s[j]) {
                ++i;
                ++j;
                if (i == reverse_s.length()) {
                    return j;
                }
            } else {
                j = next[j];
            }
        }
    }

    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        int longestPre1 = longestPalindromePrefix(s);
        int longestPre2 = longestPalindromePrefix(s, s.length());
        string addPart = s.substr(longestPre1);
        reverse(addPart.begin(), addPart.end());
        return addPart + s;
    }

};

int main() {
    string str = "aa";
    vector<int> next(2);
    Solution214 *solu;
    solu->makeNext(str, next);
    cout << next[0] << "\t" << next[1];
}