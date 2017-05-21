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
#include <bits/unordered_set.h>

using namespace std;

class Solution136 {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = (~a & b & nums[i]) | (a & ~b & ~nums[i]);
            b = (~a & ~b & nums[i]) | (~a & b & ~nums[i]);
            a = tmp;
        }
        return a | b;
    }
};

//int main() {
//    int a = 10;
//    cout << ~a;
//}