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
#include <map>

using namespace std;

class Solution154 {
public:
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

    int findMin(vector<int> &nums) {
        int pivot = findPivot_dup(nums, 0, nums.size() - 1);
        if (pivot >= nums.size() - 1) {
            return nums[0];
        } else {
            return nums[pivot + 1];
        }
    }
};
