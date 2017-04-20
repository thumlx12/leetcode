//
// Created by sensetime on 4/19/17.
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

void sortColors(vector<int> &nums) {
    if (nums.size() <= 1) {
        return;
    }
    int left = 0;
    int right = nums.size() - 1;
    int current = 0;
    for (; current <= right;) {
        if (nums[current] == 1) {
            current++;
        } else if (nums[current] == 0) {
            swap(nums[current], nums[left]);
            current++;
            left++;
        } else {
            swap(nums[current], nums[right]);
            right--;
        }
    }
}

//int main() {
//    srand((unsigned) time(NULL));
//    int a = 0;
//    int b = 2;
//    int count = 100;
//    int size = (rand() % (count - a)) + a + 1;
//    vector<int> nums;
//    for (int i = 0; i < size; ++i) {
//        int tmp = (rand() % (b - a + 1)) + a;
//        nums.push_back(tmp);
//        cout << nums[i] << "\t";
//    }
//    cout << endl;
//    vector<int> nums2={0,0,1};
//    sortColors(nums);
//    for (int i = 0; i < nums.size(); ++i) {
//        cout << nums[i] << "\t";
//    }
//}