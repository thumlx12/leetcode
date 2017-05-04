//
// Created by sensetime on 5/4/17.
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

int minimumTotal(vector<vector<int>> &triangle) {
    const int n = triangle.size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        dp[0][j] = triangle[n - 1][j];
    }
    bool current = false;
    for (int i = n - 2; 0 <= i; --i) {
        current = !current;
        for (int j = 0; j < triangle[i].size(); ++j) {
            int way1 = triangle[i][j] + dp[!current][j];
            int way2 = triangle[i][j] + dp[!current][j + 1];
            dp[current][j] = min(way1, way2);
        }
    }
    return dp[current].front();
}