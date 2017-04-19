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
vector<vector<int>> three_sums;

void twoSum(vector<int> &nums, int sum, int lo) {
    for (int i = lo, j = nums.size() - 1; i < j;) {
        if (nums[i] + nums[j] < sum) {
            i++;
        } else if (nums[i] + nums[j] > sum) {
            j--;
        } else {
            vector<int> one_set = {nums[lo - 1], nums[i], nums[j]};
            three_sums.push_back(one_set);
            while (i < j && nums[i] == nums[i + 1])
                ++i;  // 相等的跳过
            while (i < j && nums[j] == nums[j - 1])
                --j;  // 相等的跳过
            i++;
            j--;
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums) {

    if (nums.size() < 3) {
        return three_sums;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) // 相等的跳过
            continue;
        twoSum(nums, -nums[i], i + 1);
    }
    return three_sums;
}

//int main() {
//    vector<int> nums = {-1, 0, 1, 2, -1, -4};
//    vector<vector<int>> three = threeSum(nums);
//    for (int i = 0; i < three.size(); ++i) {
//        for (int j = 0; j < three[i].size(); j++) {
//            cout << three[i][j] << '\t';
//        }
//        cout << endl;
//    }
//}