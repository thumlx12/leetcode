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

//int longestPalindromePrefix(string s, int end) {
//    int j = 0;
//    for (int i = end - 1; 0 <= i; --i) {
//        if (s[i] == s[j]) {
//            ++j;
//        }
//    }
//    if (j == end) {
//        return end;
//    } else {
//        return longestPalindromePrefix(s, j);
//    }
//}
//
//string shortestPalindrome(string s) {
//    int longest = longestPalindromePrefix(s, s.length());
//    string reversePart = s.substr(longest);
//    reverse(reversePart.begin(),reversePart.end());
//    return reversePart+s;
//}

void makeNext(string& s, vector<int>& next) {
    next[0] = -1;
    for (int i = 0, j = -1; i < s.size(); ) {
        if (j == -1 || s[i] == s[j]) {
            ++i; ++j;
            if (i != s.size()) {
                if (s[i] == s[j]) {
                    next[i] = next[j];
                } else {
                    next[i] = j;
                }
            }
        } else {
            j = next[j];
        }
    }
}

string shortestPalindrome(string s) {
    if (s.empty()) return s;
    string reverse_s(s);
    reverse(reverse_s.begin(), reverse_s.end());
    int mark;
    vector<int> next(s.size());
    makeNext(s, next);

    for (int i = 0, j = 0; i < reverse_s.size(); ) {
        if (j == -1 || reverse_s[i] == s[j]) {
            ++i; ++j;
            if (i == reverse_s.size()) {
                mark = j;
            }
        } else {
            j = next[j];
        }
    }

    return mark == s.size() ? reverse_s : reverse_s + s.substr(mark);
}


//int main() {
//    string str = "avadr";
//    cout << shortestPalindrome(str);
//}