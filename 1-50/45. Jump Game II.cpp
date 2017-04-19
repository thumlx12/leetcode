//
// Created by sensetime on 4/8/17.
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

int jump(vector<int> &nums) {
    int times = 0;
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
        ++times;
        start = end + 1;
        end = nextEnd;
    }
    return times;
}

//int main() {
//    vector<int> nums1 = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8,
//                         4, 4, 2, 0, 3, 8, 5};
//    cout << jump(nums1) << endl;
//}