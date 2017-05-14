//
// Created by maolixuan on 2017/5/14.
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
#include <bits/unordered_set.h>

using namespace std;

class Solution132 {
private:

    vector<vector<bool>> getPalidromeMatrix(string &s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; 0 <= j; --j) {
                dp[i][j] = true;
            }
        }
        for (int k = 1; k < s.length(); ++k) {
            for (int i = 0; i + k < s.length(); ++i) {
                int j = i + k;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp;
    }

public:
    int minCut(string s) {
        vector<vector<bool>> isPali = getPalidromeMatrix(s);
        vector<int> minCut_dp(s.length() + 1, 0);
        for (int i = 0; i <= s.length(); ++i) {
            minCut_dp[i] = i - 1;
        }
        for (int i = 1; i <= s.length(); ++i) {
            for (int k = 0; k < i; ++k) {
                if (isPali[k][i - 1]) {
                    minCut_dp[i] = min(minCut_dp[i], minCut_dp[k] + 1);
                }
            }
        }
        return minCut_dp[s.length()];
    }
};

//int main() {
//    string s = "aab";
//    Solution132 *solu = new Solution132();
//    cout << solu->minCut(s);
//}
