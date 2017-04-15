//
// Created by sensetime on 4/15/17.
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

int uniquePaths(int m, int n) {
    if (m == 1) {
        return 1;
    }
    vector<vector<int>> dp(2, vector<int>(n, 1));
    dp[1][0] = 1;
    bool current = true;
    for (int j = 1; j < n; ++j) {
        dp[current][j] = dp[!current][j] + dp[current][j - 1];
    }

    for (int i = 2; i < m; ++i) {
        current = !current;
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                dp[current][j] = dp[!current][j];
            } else {
                dp[current][j] = dp[!current][j] + dp[current][j - 1];
            }
        }
    }
    return dp[current][n - 1];
}


//int main() {
//    cout << uniquePaths(2, 4);
//}