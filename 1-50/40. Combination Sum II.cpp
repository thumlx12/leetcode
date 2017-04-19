//
// Created by sensetime on 4/1/17.
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
vector<vector<int>> sresult;

void helper2(vector<int> &candidates, vector<int> &oneSet, int target, int start_point) {
    if (target == 0) {
        sresult.push_back(oneSet);
        return;
    }
    for (int i = start_point; i < candidates.size(); ++i) {
        if (candidates[i] > target) {
            return;
        }
        if (i && candidates[i] == candidates[i - 1] && i > start_point) {
            continue;
        }
        oneSet.push_back(candidates[i]);
        helper2(candidates, oneSet, target - candidates[i], i + 1);
        oneSet.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> oneSet;
    sort(candidates.begin(), candidates.end());
    helper2(candidates, oneSet, target, 0);
    return sresult;
}

//int main() {
//    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
//    combinationSum2(candidates, 8);
//    for (int i = 0; i < sresult.size(); ++i) {
//        for (int j = 0; j < sresult[i].size(); ++j) {
//            cout << sresult[i][j] << "\t";
//        }
//        cout << endl;
//
//    }
//}