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

int binarySearch_forward(vector<int> &nums, int lo, int hi, const int &target) {
    if (hi - lo < 1) {
        if (nums[hi] == target) {
            return hi;
        } else {
            return -1;
        }
    }
    int mi = (lo + hi) / 2;
    if (nums[mi] < target) {
        return binarySearch_forward(nums, mi + 1, hi, target);
    } else
        return binarySearch_forward(nums, lo, mi, target);
}

int binarySearch_backward(vector<int> &nums, int lo, int hi, const int &target) {
    if (hi - lo < 1) {
        if (nums[hi] == target) {
            return hi;
        } else {
            return -1;
        }
    }
    int mi = ceil((lo + hi) / 2.0);
    if (target < nums[mi]) {
        return binarySearch_backward(nums, lo, mi - 1, target);
    } else {
        return binarySearch_backward(nums, mi, hi, target);
    }

}

vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() <= 0) {
        return vector<int>{-1, -1};
    }
    int lo = binarySearch_forward(nums, 0, nums.size() - 1, target);
    if (lo == -1) {
        return vector<int>{-1, -1};
    }
    int hi = binarySearch_backward(nums, 0, nums.size() - 1, target);
    return vector<int>{lo, hi};
}

int main() {
    vector<int> nums = {2, 2, 2, 2, 2, 2};
    int a = binarySearch_forward(nums, 0, nums.size() - 1, 2);
    int b = binarySearch_backward(nums, 0, nums.size() - 1, 2);
    cout << a << endl;
    cout << b << endl;
    cout << searchRange(nums, 2) << endl;

}
