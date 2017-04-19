//
// Created by sensetime on 4/17/17.
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

int minPathSum(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (m <= 1) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += grid[0][j];
        }
        return sum;
    }
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    bool current = false;
    for (int i = 1; i < m; ++i) {
        current = !current;
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                dp[current][j] = dp[!current][j] + grid[i][j];
            } else {
                dp[current][j] = min(dp[current][j - 1], dp[!current][j]) + grid[i][j];
            }
        }

    }
    return dp[current][n - 1];
}
