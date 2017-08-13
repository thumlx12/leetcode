//
// Created by sensetime on 5/9/17.
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
#include <bitset>

using namespace std;

int longestConsecutive(vector<int> &nums) {
    int longest = 0;
    unordered_set<int> hashTable;
    for (int i = 0; i < nums.size(); ++i) {
        hashTable.insert(nums[i]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (hashTable.find(nums[i]) != hashTable.end()) {
            int pre = nums[i] - 1;
            int next = nums[i] + 1;
            while (hashTable.find(pre) != hashTable.end()) {
                hashTable.erase(pre);
                --pre;
            }
            while (hashTable.find(next) != hashTable.end()) {
                hashTable.erase(next);
                ++next;
            }
            longest = max(longest, next - pre - 1);
            hashTable.erase(nums[i]);
        }
    }
    return longest;
}

//int main() {
//    vector<int> a1 = {1, 2, 3, 4};
//    //cout << longestConsecutive(a1) << endl;
//    cout << longestConsecutive(a1);
//}