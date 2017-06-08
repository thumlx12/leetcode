//
// Created by sensetime on 6/8/17.
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
#include <bitset>

using namespace std;

class Solution209 {
public:
    int On(int s, vector<int> &nums) {
        int size = nums.size();
        int sum = 0;
        int start = 0;
        int minLength = INT_MAX;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            while (sum >= s) {
                minLength = min(minLength, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }

    int binarySeach(int target, int lo, int hi, vector<int> &nums) {
        if (hi - lo < 1) {
            return hi;
        }
        int mi = (hi + lo) / 2;
        if (nums[mi] < target) {
            return binarySeach(target, mi + 1, hi, nums);
        } else {
            return binarySeach(target, lo, mi, nums);
        }
    }

    int Ologn(int s, vector<int> &nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        vector<int> sumArr(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sumArr[i] = sumArr[i - 1] + nums[i - 1];
        }
        int minLength = INT_MAX;
        for (int i = 0; i <= nums.size(); ++i) {
            int right = binarySeach(sumArr[i] + s, i, nums.size(), nums);
            if (nums[right] < sumArr[i] + s) {
                break;
            }
            minLength = min(minLength, right - i);
        }
        return minLength == INT_MAX ? 0 : minLength;
    }

    int minSubArrayLen(int s, vector<int> &nums) {
        return Ologn(s,nums);
    }
};

int main(){

}
