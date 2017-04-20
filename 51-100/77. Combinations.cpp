//
// Created by sensetime on 4/20/17.
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

void getAllCombine(vector<vector<int>> &result, vector<int> &current, int start, int &limit, int &total) {
    if (current.size() >= limit) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < total; ++i) {
        current.push_back(i + 1);
        getAllCombine(result, current, i + 1, limit, total);
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    getAllCombine(result, current, 0, k, n);
    return result;
}

int main() {
    vector<vector<int>> result = combine(10, 9);
    cout << result.size() << endl << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}