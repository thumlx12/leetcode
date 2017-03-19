//
// Created by LixuanMao on 2017/3/19.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

/* brutal algorithm
 * bool isPalindrome(string s, int lo, int hi) {
    if (hi - lo < 1) {
        return true;
    }
    bool result = true;
    while (lo < hi) {
        if (s[lo] == s[hi]) {
            lo++;
            hi--;
        } else {
            result = false;
            break;
        }
    }
    return result;
}

string longestPalindrome(string s) {
    for (int i = s.size(); 1 <= i; --i) {
        for (int lo = 0; lo + i - 1 < s.size(); ++lo) {
            if (isPalindrome(s, lo, lo + i - 1)) {
                return s.substr(lo, i);
            }
        }
    }

}
 */

/*
 * Dynamic Planning
 */
string longestPalindrome(string s) {
    if (s.length() <= 1) {
        return s;
    }
    unsigned int n = s.length();
    int lo = 0;
    int length = 1;
    bool **DP_matrix = new bool *[n];
    for (int i = 0; i < n; ++i) {
        DP_matrix[i] = new bool[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j) {
                DP_matrix[i][j] = true;
            } else {
                DP_matrix[i][j] = false;
            }
        }
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 0; k + i < n; ++i) {
            int j = i + k;
            if (DP_matrix[i + 1][j - 1]) {
                if (s[i] == s[j]) {
                    DP_matrix[i][j] = true;
                    if (length < (k + 1)) {
                        lo = i;
                        length = k + 1;
                    }
                }
            }
        }
    }
    return s.substr(lo, length);
}
/*
 * Extension based on center point.
 */
string longestPalindrome2(string s) {
    const int length = s.size();
    if (length <= 1) {
        return s;
    }
    int maxlength = 1;
    int start;

    for (int i = 0; i < length; i++)//长度为奇数
    {
        int j = i - 1, k = i + 1;
        while (j >= 0 && k < length && s.at(j) == s.at(k)) {
            if (k - j + 1 > maxlength) {
                maxlength = k - j + 1;
                start = j;
            }
            j--;
            k++;
        }
    }
    for (int i = 0; i < length; i++)//长度为偶数
    {
        int j = i, k = i + 1;
        while (j >= 0 && k < length && s.at(j) == s.at(k)) {
            if (k - j + 1 > maxlength) {
                maxlength = k - j + 1;
                start = j;
            }
            j--;
            k++;
        }
    }
    return s.substr(start, maxlength);
}


int main() {
    string a1 = "bab";
    string a2 = "baba";
    string a3 = "babad";
    string a4 = "hannah";
    string a5 = "cbbd";
    cout << longestPalindrome(a1) << endl;
    cout << longestPalindrome(a2) << endl;
    cout << longestPalindrome(a3) << endl;
    cout << longestPalindrome(a4) << endl;
    cout << longestPalindrome(a5) << endl;
}