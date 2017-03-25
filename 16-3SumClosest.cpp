//
// Created by sensetime on 3/25/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

int closest_sum = 0;
int smallest_diff = INT_MAX;

void twoSumClosest(vector<int> &nums, int sum, int &lo, int &target) {
    for (int i = lo + 1, j = nums.size() - 1; i < j;) {
        int diff = sum - (nums[i] + nums[j]);
        if (diff < 0) {
            j--;
        } else {
            i++;
        }
        if (abs(diff) < smallest_diff) {
            smallest_diff = abs(diff);
            closest_sum = target - diff;
        }
    }
}

int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) // 相等的跳过
            continue;
        twoSumClosest(nums, (target - nums[i]), i, target);
    }
    return closest_sum;
}

//int main() {
//    vector<int> S = {0, 2, 1, -3};
//    cout << threeSumClosest(S, 1);
//}