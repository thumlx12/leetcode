//
// Created by sensetime on 5/18/17.
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
#include <queue>
#include <unordered_set>

using namespace std;

class Solution126 {
public:
    // a^a = 0
    int singleNumber(vector<int> &nums) {
        int single = nums[0];
        for(int i= 1;i<nums.size();++i){
            single ^= nums[i];
        }
        return single;
    }
};
