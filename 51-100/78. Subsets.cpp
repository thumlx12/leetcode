//
// Created by sensetime on 4/20/17.
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

void getAllSubsets(vector<int> &nums, vector<vector<int>> &result, vector<int> &current, int start) {
    if (start >= nums.size()) {
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        result.push_back(current);
        getAllSubsets(nums, result, current, i + 1);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    result.push_back(current);
    getAllSubsets(nums, result, current, 0);
    return result;
}

//int main() {
//    vector<int> nums = {1, 2, 2};
//    vector<vector<int>> result = subsets(nums);
//    cout << result.size() << endl << "-------------------" << endl;
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}

