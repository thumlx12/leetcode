//
// Created by sensetime on 3/28/17.
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

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void reverse(vector<int> &nums, int st) {
    for (int i = st, j = nums.size() - 1; i < j; ++i, --j) {
        swap(nums[i], nums[j]);
    }
}

void nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1) {
        return;
    }
    int i = nums.size() - 2;
    for (; 0 <= i; --i) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }
    if (i < 0) {
        reverse(nums, 0);
        return;
    }
    int j = nums.size() - 1;
    while (i < j && nums[i] >= nums[j]) {
        --j;
    }
    swap(nums[i], nums[j]);
    reverse(nums, i + 1);
}

//int main() {
//    vector<int> nums = {1, 2, 3, 4};
//    for (int i = 0; i < 24; i++) {
//        nextPermutation(nums);
//        for (int j = 0; j < nums.size(); ++j) {
//            cout << nums[j] << ",";
//        }
//        cout << endl;
//    }
//}
