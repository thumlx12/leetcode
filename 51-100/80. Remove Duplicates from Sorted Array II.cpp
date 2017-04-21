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

int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 2) {
        return nums.size();
    }
    int times = 0;
    int deDupLength = 1;
    for (int i = 1; i < nums.size();) {
        if (nums[i] == nums[i - 1]) {
            if (times == 1) {
                nums.erase(nums.begin() + i);
            } else {
                times++;
                deDupLength++;
                ++i;
            }
        } else {
            times = 0;
            deDupLength++;
            ++i;
        }
    }
    return deDupLength;
}

//int main() {
//    vector<int> nums = {1, 1, 1, 1, 3, 3};
//    int deDupLength = removeDuplicates(nums);
//    for (int i = 0; i < deDupLength; ++i) {
//        cout << nums[i] << "\t";
//    }
//}