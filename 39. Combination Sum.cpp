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

vector<vector<int>> result;

void helper(vector<int> &candidates, vector<int> &oneSet, int target, int start_point) {
    if (target == 0) {
        result.push_back(oneSet);
        return;
    }
    if (target < 0) {
        return;
    }
    for (int i = start_point; i < candidates.size(); ++i) {
        oneSet.push_back(candidates[i]);
        helper(candidates, oneSet, target - candidates[i], start_point);
        start_point++;
        oneSet.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> oneSet;
    helper(candidates, oneSet, target, 0);
    return result;
}

//int main() {
//    vector<int> candidates = {2, 3, 6, 7};
//    combinationSum(candidates, 7);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}