//
// Created by sensetime on 4/5/17.
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


int firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        while ((nums[i] > 0) && (nums[i] != i + 1) && (nums[i] <= nums.size()) && (nums[i] != nums[nums[i] - 1])) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            return (i + 1);
        }
    }
    return (nums.size() + 1);
}
//
//int main() {
//    vector<vector<int>> numsv = {
//            {1,  2, 0},
//            {3,  4, -1, 1},
//            {3,  4, 5,  6, 7},
//            {4, 4, 3,  2, 1},
//            {2,  1}
//    };
//    for (int i = 0; i < numsv.size(); ++i) {
//        cout << firstMissingPositive(numsv[i]) << endl;
//    }
//}