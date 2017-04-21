//
// Created by sensetime on 4/21/17.
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

int findPivot_dup(vector<int> &nums, int lo, int hi) {
    if (hi - lo < 1) {
        return lo;
    }
    int mi = (lo + hi) / 2;
    if (nums[lo] < nums[mi]) {
        if (nums[mi] <= nums[mi + 1]) {
            return findPivot_dup(nums, mi + 1, hi);
        } else {
            return mi;
        }
    } else if (nums[mi] < nums[lo]) {
        return findPivot_dup(nums, lo, mi - 1);
    } else {
        int p1 = findPivot_dup(nums, lo, mi);
        int p2 = findPivot_dup(nums, mi + 1, hi);
        if (nums[p1] > nums[p1 + 1]) {
            return p1;
        } else {
            return p2;
        }
    }
}

int binarySearch_dup(vector<int> &nums, int lo, int hi, const int &target) {
    if (hi - lo < 1) {
        if (nums[hi] == target) {
            return lo;
        } else {
            return -1;
        }
    }
    int mi = (lo + hi) / 2;
    if (nums[mi] < target) {
        return binarySearch_dup(nums, mi + 1, hi, target);
    } else if (target < nums[mi]) {
        return binarySearch_dup(nums, lo, mi - 1, target);
    } else {
        return mi;
    }
}

bool search_dup(vector<int> &nums, int target) {
    if (nums.size() <= 0) {
        return false;
    }
    int pivot = findPivot_dup(nums, 0, nums.size() - 1);
    if (nums[0] <= target && target <= nums[pivot]) {
        if (binarySearch_dup(nums, 0, pivot, target) != -1)
            return true;
        else
            return false;
    } else {
        if (binarySearch_dup(nums, pivot + 1, nums.size() - 1, target) != -1)
            return true;
        else
            return false;
    }
}

//int main() {
//    vector<int> nums = {1, 2, 2, 2, 0};
//    cout << search_dup(nums, 0);
//}