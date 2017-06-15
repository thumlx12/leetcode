//
// Created by sensetime on 6/10/17.
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
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <bitset>

using namespace std;

class Solution213 {
public:
    int rob_orginal(vector<int> &num) {
        int i = 0;
        int e = 0;

        for (int k = 0; k < num.size(); k++) {
            int tmp = i;
            i = e + num[k];
            e = max(tmp, e);
        }
        return max(i, e);
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> subNums1(nums.begin(), nums.end() - 1);
        vector<int> subNums2(nums.begin() + 1, nums.end());
        return max(rob_orginal(subNums1), rob_orginal(subNums2));
    }
};

//int main() {
//    vector<int> nums = {2, 1, 1, 2};
//    Solution213 *solu;
//    cout << solu->rob(nums);
//}
