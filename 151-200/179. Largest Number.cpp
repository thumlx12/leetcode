//
// Created by sensetime on 6/3/17.
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
#include <map>

using namespace std;

class Solution179 {
public:

    bool strCompare(string &s1, string &s2) {
        return (s1 + s2) >= (s2 + s1);
    }

    void quickSort(vector<string> &nums, int lo, int hi) {
        if (hi - lo < 2) {
            return;
        }
        int mi = partition(nums, lo, hi - 1);
        quickSort(nums, lo, mi);
        quickSort(nums, mi + 1, hi);
    }

    int partition(vector<string> &nums, int lo, int hi) {
        swap(nums[lo], nums[lo + rand() % (hi - lo + 1)]);
        string pivot = nums[lo];
        while (lo < hi) {
            while ((lo < hi) && strCompare(nums[hi], pivot)) {
                hi--;
            }
            nums[lo] = nums[hi];
            while ((lo < hi) && strCompare(pivot, nums[lo])) {
                lo++;
            }
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }

    void trim(string &s1) {
        int nonZero = 0;
        for (; nonZero < s1.length(); ++nonZero) {
            if (s1[nonZero] != '0') {
                break;
            }
        }
        if (nonZero >= s1.length()) {
            s1 = "0";
        } else {
            s1 = s1.substr(nonZero);
        }
    }

    string largestNumber(vector<int> &nums) {
        vector<string> nums_str;
        for (int i = 0; i < nums.size(); ++i) {
            nums_str.push_back(to_string(nums[i]));
        }
        quickSort(nums_str, 0, nums_str.size());
        string largestNum = "";
        for (int i = nums_str.size() - 1; 0 <= i; --i) {
            largestNum += nums_str[i];
        }
        trim(largestNum);
        return largestNum;
    }
};
//
//int main() {
//    Solution179 *solu;
//    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    cout << solu->largestNumber(nums);
//}