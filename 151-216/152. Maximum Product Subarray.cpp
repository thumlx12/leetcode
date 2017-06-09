//
// Created by maolixuan on 2017/5/28.
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

using namespace std;

int maxProduct(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int maxPos = nums[0];
    int minNeg = nums[0];
    int ret = nums[0];
    for(int i=1;i<nums.size();++i){
        int tmp1 = maxPos * nums[i];
        int tmp2 = minNeg * nums[i];
        maxPos =max(nums[i], max(tmp1,tmp2));
        minNeg =min(nums[i], min(tmp1,tmp2));
        ret = max(ret, maxPos);
    }
    return ret;

}
