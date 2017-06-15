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

class Solution219 {
public:
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
};
