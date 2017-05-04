//
// Created by maolixuan on 2017/5/3.
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

int numDistinct(string s, string t) {
    const int m = s.length();
    const int n = t.length();
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = 0;
    }
    bool current = false;
    for (int i = 1; i <= m; ++i) {
        current = !current;
        dp[current][0] = 1;
        for (int j = 1; j <= n; ++j) {
            dp[current][j] = dp[!current][j] + ((s[i - 1] == t[j - 1]) ? dp[!current][j - 1] : 0);
        }
    }
    return dp[current][n];
}

