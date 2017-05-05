//
// Created by sensetime on 5/5/17.
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

int maxProfit2(vector<int> &prices) {
    if (prices.size() <= 1) {
        return 0;
    }
    int maxProfit = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (prices[i + 1] > prices[i]) {
            maxProfit += (prices[i + 1] - prices[i]);
        }
    }
    return maxProfit;
}
