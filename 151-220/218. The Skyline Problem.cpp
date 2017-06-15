//
// Created by sensetime on 6/15/17.
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

class Solution218 {
public:
    unordered_set<int> deletedHeight;

    static bool pairCmp(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first) {
            return true;
        }
        if (a.first > b.first) {
            return false;
        }
        return a.second <= b.second;
    }

    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> ans;
        if (buildings.size() <= 0) {
            return ans;
        }
        vector<pair<int, int>> criticalPoints;
        for (int i = 0; i < buildings.size(); ++i) {
            criticalPoints.push_back({buildings[i][0], -buildings[i][2]});
            criticalPoints.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(criticalPoints.begin(), criticalPoints.end(), pairCmp);
        priority_queue<int> heightHeap;
        heightHeap.push(0);
        int prev = 0;
        for (int i = 0; i < criticalPoints.size(); ++i) {
            if (criticalPoints[i].second < 0) {
                heightHeap.push(-criticalPoints[i].second);
            } else {
                deletedHeight.insert(criticalPoints[i].second);
            }
            int currentPeak;
            while (deletedHeight.count(currentPeak = heightHeap.top())) {
                deletedHeight.erase(currentPeak);
                heightHeap.pop();
            }
            if (prev != currentPeak) {
                ans.push_back({criticalPoints[i].first, currentPeak});
                prev = currentPeak;
            }
        }
        if (ans.back().first != criticalPoints.back().first) {
            ans.push_back({criticalPoints.back().first, 0});
        }
        return ans;
    }
};

//int main() {
//    vector<vector<int>> buildings{
//            {2,  9,  10},
//            {3,  7,  15},
//            {5,  12, 12},
//            {15, 20, 10},
//            {19, 24, 8}};
//    vector<vector<int>> buildings2{
//            {0,  5,  7},
//            {5,  10, 7},
//            {5,  10, 12},
//            {10, 15, 7},
//            {15, 20, 7},
//            {15, 20, 12},
//            {20, 25, 7}
//    };
//    Solution218 *solu = new Solution218();
//    vector<pair<int, int>> skyline = solu->getSkyline(buildings2);
//    for (int i = 0; i < skyline.size(); ++i) {
//        cout << skyline[i].first << "\t" << skyline[i].second << endl;
//    }
//}