//
// Created by sensetime on 4/14/17.
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

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() <= 0) {
        return {};
    }

    int count = 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> spiralArr;//(m * n, 0);
    bool isHorizon = true;
    bool isRise = true;
    int layer = 0;
    for (int i = 0, j = 0; count < m * n; ++count) {
        spiralArr.push_back(matrix[i][j]);
        if (isHorizon) {
            if (isRise) {
                if (j < n - layer - 1) {
                    j++;
                } else {
                    i++;
                    isHorizon = !isHorizon;
                }
            } else {
                if (layer < j) {
                    j--;
                } else {
                    i--;
                    isHorizon = !isHorizon;
                }
            }
        } else {
            if (isRise) {
                if (i < m - layer - 1) {
                    i++;
                } else {
                    j--;
                    isRise = !isRise;
                    isHorizon = !isHorizon;
                }
            } else {
                if (layer + 1 < i) {
                    i--;
                } else {
                    j++;
                    isRise = !isRise;
                    isHorizon = !isHorizon;
                    layer++;
                }
            }
        }
    }
    return spiralArr;
}

//int main() {
//    vector<vector<int>> matrix = {
//            {0,  1,  2,  3},
//            {4,  5,  6,  7},
//            {8,  9,  10, 11},
//            {12, 13, 14, 15}
//    };
//    vector<int> arr = spiralOrder(matrix);
//    for (int i = 0; i < arr.size(); ++i) {
//        cout << arr[i] << "\t";
//    }
//    vector<vector<int>> matrix2 = {};
//    spiralOrder(matrix2);
//}