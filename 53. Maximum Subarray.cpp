//
// Created by sensetime on 4/14/17.
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

int maxSubArray(vector<int> &nums) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int left = 0, right = 0;
    for (; right < nums.size(); ++right) {
        max_sum = max(max_sum, current_sum + nums[right]);
        if (current_sum + nums[right] < 0) {
            left = right + 1;
            current_sum = 0;
        } else {
            current_sum += nums[right];
        }

    }
    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
}