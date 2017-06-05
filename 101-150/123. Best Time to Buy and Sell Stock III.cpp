//
// Created by maolixuan on 2017/5/6.
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

int maxProfitKTrans(vector<int> &prices, int k) {
    if (prices.size() <= 1) {
        return 0;
    }
    k = k < (prices.size() - 1) ? k : (prices.size() - 1);
    const int n = prices.size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    bool current = false;
    for (int i = 1; i <= k; ++i) {
        current = !current;
        dp[current][0] = 0;
        int tmpMax = dp[!current][0] - prices[0];
        for (int j = 1; j < n; ++j) {
            dp[current][j] = max(dp[current][j - 1], tmpMax + prices[j]);
            tmpMax = max(tmpMax, dp[!current][j] - prices[j]);
        }
    }
    return dp[current][n - 1];
}

int maxProfit3(vector<int> &prices) {
    if (prices.size() <= 1) {
        return 0;
    }
    return maxProfitKTrans(prices, 2);
}

//
int main() {
    int k = 12;
    cout << ceil((float) k / 2);
}
