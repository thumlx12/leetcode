//
// Created by sensetime on 6/10/17.
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

using namespace std;

class Solution210 {
public:

    /* improve complexity to O(V+E) */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<int> courseOrder;
        if (numCourses <= 0) {
            return courseOrder;
        }
        if (numCourses <= 1) {
            courseOrder.push_back(0);
            return courseOrder;
        }
        unordered_map<int, vector<int>> courseGraph;
        unordered_map<int, int> node2InDegree;
        for (int i = 0; i < prerequisites.size(); ++i) {
            courseGraph[prerequisites[i].second].push_back(prerequisites[i].first);
            node2InDegree[prerequisites[i].first]++;
        }
        unordered_set<int> zeroInDegreeNodes;
        for (int i = 0; i < numCourses; ++i) {
            if (!node2InDegree.count(i)) {
                zeroInDegreeNodes.insert(i);
            }
        }
        int leftCourses = numCourses;
        while (leftCourses > 0) {
            if (zeroInDegreeNodes.size() <= 0) {
                vector<int> emptyArr;
                return emptyArr;
            }
            leftCourses -= zeroInDegreeNodes.size();
            unordered_set<int> tmpSet;
            for (unordered_set<int>::const_iterator iter = zeroInDegreeNodes.begin();
                 iter != zeroInDegreeNodes.end(); ++iter) {
                int node = (*iter);
                if (courseGraph.count(node)) {
                    for (int t = 0; t < courseGraph[node].size(); ++t) {
                        if (--node2InDegree[courseGraph[node][t]] <= 0) {
                            tmpSet.insert(courseGraph[node][t]);
                        }
                    }
                }
                courseOrder.push_back(node);
            }
            zeroInDegreeNodes.clear();
            zeroInDegreeNodes = tmpSet;

        }
        return courseOrder;
    }
};

//int main() {
//    int num = 3;
//    vector<pair<int, int>> prerequisites;
//    Solution210 *solu;
//    vector<int> order = solu->findOrder(num, prerequisites);
//    for (int i = 0; i < order.size(); ++i) {
//        cout << order[i] << "\t";
//    }
//}