//
// Created by sensetime on 4/14/17.
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

bool canJump(vector<int>& nums) {
    int ans=true;
    int start = 0;
    int end = 0;
    int nextEnd = 0;
    while (!(start <= nums.size() - 1 && nums.size() - 1 <= end)) {
        for (int i = start; i <= end; ++i) {
            int nextPoint = i + nums[i];
            if (nextEnd < nextPoint) {
                nextEnd = nextPoint;
            }
        }
        if(nextEnd <= start){
            return false;
        }
        start = end + 1;
        end = nextEnd;
    }
    return ans;
}