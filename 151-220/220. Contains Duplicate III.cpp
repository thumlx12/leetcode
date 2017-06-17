//
// Created by sensetime on 6/15/17.
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
#include <queue>

using namespace std;

class Solution220 {
public:

    bool t_barrelSort(vector<int> &nums, int k, long long t) {
        int minNum = nums[0];
        int maxNum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        unsigned long long barrelNum = ceil(((double) maxNum - minNum + 1) / (t + 1));
        unordered_map<long long, vector<pair<int, int>>> barrelMap;
        for (int i = 0; i < nums.size(); ++i) {
            long long idx = ((long long) nums[i] - minNum) / (t + 1);
            barrelMap[idx].push_back({nums[i], i});
        }
        for (unordered_map<long long, vector<pair<int, int>>>::const_iterator iter = barrelMap.begin();
             iter != barrelMap.end(); ++iter) {
            if (2 <= iter->second.size()) {
                for (int p = 0; p < iter->second.size() - 1; ++p) {
                    if (iter->second[p + 1].second - iter->second[p].second <= k) {
                        return true;
                    }
                }
            }
            long long key = iter->first;
            if (barrelMap.count(key - 1)) {
                for (int p = 0; p < iter->second.size(); ++p) {
                    long long originValue = iter->second[p].first;
                    long long originIdx = iter->second[p].second;
                    for (int q = 0; q < barrelMap[key - 1].size(); ++q) {
                        long long lastValue = barrelMap[key - 1][q].first;
                        long long lastIdx = barrelMap[key - 1][q].second;
                        if (abs(originIdx - lastIdx) <= k && originValue - lastValue <= t) {
                            return true;
                        }
                    }
                }
            }
            if (barrelMap.count(key + 1)) {
                for (int p = 0; p < iter->second.size(); ++p) {
                    long long originValue = iter->second[p].first;
                    long long originIdx = iter->second[p].second;
                    for (int q = 0; q < barrelMap[key + 1].size(); ++q) {
                        long long nextValue = barrelMap[key + 1][q].first;
                        long long nextIdx = barrelMap[key + 1][q].second;
                        if (abs(originIdx - nextIdx) <= k && nextValue - originValue <= t) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        if (k <= 0) {
            return false;
        }
        unordered_map<int, vector<int>> value2indice;
        for (int i = 0; i < nums.size(); ++i) {
            value2indice[nums[i]].push_back(i);
        }
        for (unordered_map<int, vector<int>>::const_iterator iter = value2indice.begin();
             iter != value2indice.end(); ++iter) {
            for (int i = 0; i < iter->second.size() - 1; ++i) {
                if (abs(iter->second[i] - iter->second[i + 1]) <= k) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.size() < 2 || k <= 0 || t < 0) {
            return false;
        }
        if (t == 0) {
            return containsNearbyDuplicate(nums, k);
        }
        int target = (long long) t;
        return t_barrelSort(nums, k, target);
    }
};
//
//int main() {
//    vector<int> nums = {-1, 2147483647};
//    Solution220 *solu = new Solution220();
//    cout << solu->containsNearbyAlmostDuplicate(nums, 1, 2147483647);
//}