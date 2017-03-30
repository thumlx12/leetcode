//
// Created by sensetime on 3/30/17.
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

int findPivot(vector<int> &nums, int lo, int hi) {
    if (hi - lo < 1) {
        return lo;
    }
    int mi = (lo + hi) / 2;
    if (nums[lo] <= nums[mi]) {
        if (nums[mi] < nums[mi + 1]) {
            return findPivot(nums, mi + 1, hi);
        } else {
            return mi;
        }
    } else {
        return findPivot(nums, lo, mi - 1);
    }
}

int binarySearch(vector<int> &nums, int lo, int hi, const int &target) {
    if (hi - lo < 1) {
        if (nums[hi] == target) {
            return lo;
        } else {
            return -1;
        }
    }
    int mi = (lo + hi) / 2;
    if (nums[mi] < target) {
        return binarySearch(nums, mi + 1, hi, target);
    } else if (target < nums[mi]) {
        return binarySearch(nums, lo, mi - 1, target);
    } else {
        return mi;
    }
}

int search(vector<int> &nums, int target) {
    if (nums.size() <= 0) {
        return -1;
    }
    int pivot = findPivot(nums, 0, nums.size() - 1);
    if (nums[0] <= target && target <= nums[pivot]) {
        return binarySearch(nums, 0, pivot, target);
    } else {
        return binarySearch(nums, pivot + 1, nums.size() - 1, target);
    }
}


//int main() {
//    vector<int> nums = {8, 9, 2, 3, 4};
//    int a = search(nums, 9);
//    cout << a;
//}
