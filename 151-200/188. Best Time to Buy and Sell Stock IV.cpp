//
// Created by sensetime on 6/5/17.
//

class Solution188 {
public:

    int maxProfitKTrans(vector<int> &prices, int k) {
        if (prices.size() <= 1) {
            return 0;
        }
        if (k >= prices.size() - 1) { // simple case
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                ans += max(prices[i] - prices[i - 1], 0);
            }
            return ans;
        }
        const int n = prices.size();
        vector <vector<int>> dp(2, vector<int>(n, 0));
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


    int maxProfit(int k, vector<int> &prices) {
        return maxProfitKTrans(prices, k);
    }

};