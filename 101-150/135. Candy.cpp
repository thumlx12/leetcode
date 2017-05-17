//
// Created by sensetime on 5/17/17.
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
#include <bits/unordered_set.h>

using namespace std;


int candy(vector<int> &ratings) {
    const int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i <= n - 1; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; 0 <= i; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int totalCandies = 0;
    for (int i = 0; i < n; ++i) {
        totalCandies += candies[i];
    }
    return totalCandies;
}

//int main() {
//    vector<int> ratings = {1, 3, 4, 3, 2, 1};
//    cout << candy(ratings);
//}