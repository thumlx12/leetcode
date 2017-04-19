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

int trap_concise(vector<int> &height) {
    int l = 0, r = height.size() - 1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}

int trap(vector<int> &height) {
    const int originalSize = height.size();
    height.push_back(0);
    int leftEdge, rightEdge;
    int totalUnit = 0;
    for (int i = 0; i < originalSize - 1;) {
        if (height[i] > height[i + 1]) {
            leftEdge = i;
            rightEdge = ((leftEdge + 2) < originalSize) ? (leftEdge + 2) : originalSize - 1;
            for (int p = rightEdge; p < originalSize; ++p) {
                if (height[leftEdge] <= height[p]) {
                    rightEdge = p;
                    break;
                } else {
                    if (height[p - 1] < height[p] && height[p + 1] <= height[p]) {
                        if (height[rightEdge] < height[p]) {
                            rightEdge = p;
                        }
                    }
                }
            }
            if (rightEdge < originalSize) {
                int oneSectorWater = (rightEdge - leftEdge - 1) *
                                     ((height[leftEdge] < height[rightEdge]) ? height[leftEdge] : height[rightEdge]);
                for (int k = leftEdge + 1; k < rightEdge; ++k) {
                    oneSectorWater -= (height[k] < height[rightEdge]) ? height[k] : height[rightEdge];
                }
                totalUnit += oneSectorWater;
            }
            i = rightEdge;
        } else {
            ++i;
        }
    }
    return totalUnit;
}

//int main() {
//    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//    cout << trap_concise(height) << endl;
//
//    vector<int> height2 = {5, 4, 1, 2};
//    cout << trap_concise(height2) << endl;
//
//    vector<int> height3 = {5, 2, 1, 2, 1, 5};
//    cout << trap_concise(height3) << endl;
//
//    vector<int> height4 = {9, 6, 8, 8, 5, 6, 3};
//    cout << trap_concise(height4) << endl;
//}