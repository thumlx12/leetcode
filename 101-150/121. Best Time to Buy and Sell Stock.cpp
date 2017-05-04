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

int maxProfit(vector<int> &prices) {
    int maxP = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
        minPrice = min(minPrice, prices[i]);
        maxP = max(maxP, prices[i] - minPrice);
    }
    return maxP;
}
