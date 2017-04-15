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

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    if (m <= 1) {
        for (int i = 0; i < obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i] == 1) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> dp(2, vector<int>(n, 1));
    dp[0][0] = 1 && !obstacleGrid[0][0];
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] && !obstacleGrid[0][j];
    }
    dp[1][0] = dp[0][0] && !obstacleGrid[1][0];
    for (int j = 1; j < n; ++j) {
        dp[1][j] = (obstacleGrid[1][j] == 1) ? 0 : (dp[0][j] + dp[1][j - 1]);
    }

    bool current = true;
    for (int i = 2; i < m; ++i) {
        current = !current;
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                dp[current][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[!current][j];
            } else {
                dp[current][j] = (obstacleGrid[i][j] == 1) ? 0 : (dp[!current][j] + dp[current][j - 1]);
            }
        }

    }
    return dp[current][n - 1];
}

int main() {
    vector<vector<int>> ob = {
            {0, 0},
            {0, 0}
    };
    cout << uniquePathsWithObstacles(ob);
}