//
// Created by maolixuan on 2017/6/11.
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

class Solution215 {
public:

    int partition(vector<int> &nums, int lo, int hi) {
        swap(nums[lo], nums[lo + rand() % (hi - lo + 1)]);
        int pivot = nums[lo];
        while (lo < hi) {
            while ((lo < hi) && pivot <= nums[hi]) {
                --hi;
            }
            nums[lo] = nums[hi];
            while ((lo < hi) && nums[lo] <= pivot) {
                ++lo;
            }
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }

    void quickSort(vector<int> &nums, int lo, int hi) {
        if (hi - lo < 1) {
            return;
        }
        int p = partition(nums, lo, hi);
        quickSort(nums, lo, p - 1);
        quickSort(nums, p + 1, hi);
    }

    int quickSelect(vector<int> &nums, int lo, int hi, int k) {
        if (hi - lo < 1) {
            return nums[lo];
        }
        int p = partition(nums, lo, hi);
        if (p == k) {
            return nums[p];
        }
        if (p > k) {
            return quickSelect(nums, lo, p - 1, k);
        } else {
            return quickSelect(nums, p + 1, hi, k);
        }
    }

    int heapWaytoFind(vector<int> &nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for(int i=0;i<k-1;++i){
            maxHeap.pop();
        }
        return maxHeap.top();
    }

    int findKthLargest(vector<int> &nums, int k) {
        return heapWaytoFind(nums, k);
    }
};

//
//int main() {
//    srand((unsigned) time(NULL));
//    int vec_size = 200;
//    vector<int> nums;
//    for (int k = 0; k < vec_size; ++k) {
//        nums.push_back(rand() % 300);
//    }
//    Solution215 *solu;
//    solu->quickSort(nums, 0, nums.size() - 1);
//    for (int i = 0; i < nums.size(); ++i) {
//        cout << nums[i] << "\t";
//    }
//    vector<int> nums = {2, 1};
//    Solution215 *solu;
//    cout << solu->findKthLargest(nums, 1);
//}
