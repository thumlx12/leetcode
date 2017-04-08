//
// Created by sensetime on 4/8/17.
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

void getAllPermutation(vector<int> &nums, vector<vector<int>> &result, vector<int> &current, int start) {
    if (start >= nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        getAllPermutation(nums, result, current, start + 1);
        current.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    getAllPermutation(nums, result, current, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    permute(nums);
}

