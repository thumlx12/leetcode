//
// Created by sensetime on 6/8/17.
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
#include <map>
#include <bitset>

using namespace std;

class Solution207 {
public:

    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        if (numCourses <= 1) {
            return true;
        }
        unordered_map<int, vector<int>> courseGraph;
        unordered_map<int, int> node2InDegree;
        for (int i = 0; i < prerequisites.size(); ++i) {
            courseGraph[prerequisites[i].second].push_back(prerequisites[i].first);
            node2InDegree[prerequisites[i].first]++;
        }
        vector<int> zeroInDegreeNodes;
        for (int i = 0; i < numCourses; ++i) {
            if (!node2InDegree.count(i)) {
                zeroInDegreeNodes.push_back(i);
            }
        }
        int leftCourses = numCourses;
        while (true) {
            if (zeroInDegreeNodes.size() <= 0) {
                return false;
            }
            leftCourses -= zeroInDegreeNodes.size();
            if (leftCourses <= 0) {
                return true;
            }
            for (int k = 0; k < zeroInDegreeNodes.size(); ++k) {
                int node = zeroInDegreeNodes[k];
                for (int t = 0; t < courseGraph[node].size(); ++t) {
                    node2InDegree[courseGraph[node][t]]--;
                }
                node2InDegree.erase(node);
            }
            zeroInDegreeNodes.clear();
            for (unordered_map<int, int>::const_iterator iter = node2InDegree.begin();
                 iter != node2InDegree.end(); ++iter) {
                if ((*iter).second <= 0) {
                    zeroInDegreeNodes.push_back((*iter).first);
                }
            }
        }
    }
};
