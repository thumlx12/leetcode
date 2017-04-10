//
// Created by sensetime on 4/10/17.
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

void getAllUniquePermutation(vector<int> nums, vector<vector<int>> &result, int start) {
    if (start >= nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        if (i == start || nums[i] != nums[start]) {
            swap(nums[start], nums[i]);
            getAllUniquePermutation(nums, result, start + 1);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    getAllUniquePermutation(nums, result, 0);
    return result;

}

//int main() {
//    vector<int> nums = {2, 2, 1, 1};
//    vector<vector<int>> result = permuteUnique(nums);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << '\t';
//        }
//        cout << endl;
//    }
//    cout << result.size();
//}