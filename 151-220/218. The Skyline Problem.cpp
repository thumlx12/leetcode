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

class heapCmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

class Solution218 {
public:

    static bool keyPointCmp(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first) {
            return true;
        }
        if (a.first > b.first) {
            return false;
        }
        return a.second <= b.second;
    }

    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> skylines;
        priority_queue<pair<int, int>, vector<pair<int, int>>, heapCmp> maxHeightHeap;
        vector<pair<int, int>> keyPoints;
        map<pair<int, int>, int> left_height2right;
        for (int i = 0; i < buildings.size(); ++i) {
            keyPoints.push_back({buildings[i][0], -buildings[i][2]});
            keyPoints.push_back({buildings[i][1], buildings[i][2]});
            left_height2right[{buildings[i][0], buildings[i][2]}] = buildings[i][1];
        }
        sort(keyPoints.begin(), keyPoints.end(), keyPointCmp);
        maxHeightHeap.push({-1, 0});
        pair<int, int> prevTop = {-1, 0};
        pair<int, int> curTop;
        unordered_set<int> outdatedBuildings;
        for (int i = 0; i < keyPoints.size(); ++i) {
            if (keyPoints[i].second < 0) {
                maxHeightHeap.push({keyPoints[i].first, -keyPoints[i].second});
            } else {
                outdatedBuildings.insert(keyPoints[i].first);
            }
            while (true) {
                curTop = maxHeightHeap.top();
                int rightEdge = left_height2right[{curTop.first, curTop.second}];
                if (outdatedBuildings.count(rightEdge)) {
                    maxHeightHeap.pop();
                } else {
                    break;
                }
            }
            if (curTop.second != prevTop.second) {
                skylines.push_back({keyPoints[i].first, curTop.second});
                prevTop = curTop;
            }
        }
        return skylines;
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
//    vector<vector<int>> buildings3{
//            {0, 2, 3},
//            {2, 5, 3},
//
//    };
//
//    Solution218 *solu = new Solution218();
//    vector<pair<int, int>> skyline = solu->getSkyline(buildings3);
//    for (int i = 0; i < skyline.size(); ++i) {
//        cout << skyline[i].first << "\t" << skyline[i].second << endl;
//    }
//}