//
// Created by sensetime on 4/26/17.
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

void getAllSubsetsWithDup(vector<int> &nums, vector<vector<int>> &result,
                          vector<bool> &used, vector<int> &current,
                          int start) {
    if (start >= nums.size()) {
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1] || used[i - 1]) {
            used[i] = true;
            current.push_back(nums[i]);
            result.push_back(current);
            getAllSubsetsWithDup(nums, result, used, current, i + 1);
            current.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    result.push_back(current);

    sort(nums.begin(), nums.end());
    getAllSubsetsWithDup(nums, result, used, current, 0);
    return result;
}

//int main() {
//    vector<int> nums = {1, 2, 2};
//    vector<vector<int>> result = subsetsWithDup(nums);
//    cout << result.size() << endl << "-------------------" << endl;
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}

