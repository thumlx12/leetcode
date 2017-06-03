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

class Solution162 {
public:
    int findPeakElement(vector<int>& nums) {
      int lo = 0;
      int hi = nums.size()-1;
      while(lo<hi){
        int mi = (lo + hi)/2;
        if(nums[mi]<nums[mi+1]){
          lo = mi+1;
        }else{
          hi = mi;
        }
      }
      return lo;
    }
};
