//
// Created by sensetime on 3/22/17.
//

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

#define ifMatch(s, p) ( (s) ==(p) || (p)=='.')

bool decideMatchRecursively(string s, string p, int lo1, int lo2) {
    if (lo2 >= p.length()) {
        return (lo1 >= s.length());
    }
    if (lo2 == p.length() - 1) {
        return ((lo1 == s.length() - 1) && ifMatch(s[lo1], p[lo2]));
    }
    if (p[lo2 + 1] != '*') {
        if (lo1 >= s.length()) {
            return false;
        }
        if (ifMatch(s[lo1], p[lo2])) {
            return decideMatchRecursively(s, p, lo1 + 1, lo2 + 1);
        } else {
            return false;
        }
    }
    for (; lo1 < s.length() && ifMatch(s[lo1], p[lo2]); ++lo1) {
        if (decideMatchRecursively(s, p, lo1, lo2 + 2)) {
            return true;
        }
    }
    return decideMatchRecursively(s, p, lo1, lo2 + 2);
}

bool decideMathcDP(string s, string p) {
    const int lenS = s.length();
    const int lenP = p.length();
    vector<vector<bool>> dp(lenS + 1, vector<bool>(lenP + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < lenS + 1; ++i) {
        for (int j = 1; j < lenP + 1; ++j) {
            if (p[j - 1] != '*') {
                dp[i][j] = (i > 0) && (dp[i - 1][j - 1]) && (ifMatch(s[i - 1], p[j - 1]));
            } else {
                dp[i][j] = dp[i][j - 2] || (i > 0 && ifMatch(s[i - 1], p[j - 2])) && dp[i - 1][j];
            }
        }
    }
    return dp[lenS][lenP];
}

bool isMatch(string s, string p) {
    return decideMatchRecursively(s, p, 0, 0);
}

int main() {
    string s = "aab";
    string p = "c*a*ab";
    if (decideMathcDP(s, p)) {
        cout << "match" << endl;
    } else {
        cout << "not match" << endl;
    }
}