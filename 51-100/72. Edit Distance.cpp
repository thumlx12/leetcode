//
// Created by sensetime on 4/18/17.
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

int minDistance(string word1, string word2) {
    const int n = word1.length();
    const int m = word2.length();
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = i;
    }
    bool current = false;
    for (int i = 1; i <= n; ++i) {
        current = !current;
        dp[current][0] = i;
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[current][j] = min(min(dp[!current][j - 1], dp[!current][j] + 1), dp[current][j - 1] + 1);
            } else {
                dp[current][j] = min(min(dp[!current][j - 1] + 1, dp[!current][j] + 1), dp[current][j - 1] + 1);
            }
        }
    }
    return dp[current][m];

}

//int main() {
//    string s1 = "a";
//    string s2 = "a";
//    cout << minDistance(s1, s2);
//}