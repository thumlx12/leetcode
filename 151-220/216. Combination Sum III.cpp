//
// Created by maolixuan on 2017/6/11.
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

class Solution216 {
public:
    vector<vector<int>> result;

    void findAllCombination(int start, int currentLeft, int currentUsed, vector<int> &oneSet) {
        if (currentUsed == 0 && currentLeft == 0) {
            result.push_back(oneSet);
            return;
        }
        if (currentUsed == 0 || currentLeft == 0 ) {
            return;
        }
        for (int i = start; i < 10; ++i) {
            if (currentLeft - i < 0) {
                break;
            }
            oneSet.push_back(i);
            findAllCombination(i + 1, currentLeft - i, currentUsed - 1, oneSet);
            oneSet.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> oneSet;
        findAllCombination(1, n, k, oneSet);
        return result;
    }
};

//int main() {
//    Solution216 *solu = new Solution216;
//    vector<vector<int>> result = solu->combinationSum3(3, 9);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}


