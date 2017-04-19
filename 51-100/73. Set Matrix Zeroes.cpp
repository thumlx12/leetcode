//
// Created by sensetime on 4/18/17.
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

void setZeroes(vector<vector<int>> &matrix) {
    bool isFirstColumnZero = false;

    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][0] == 0) {
            isFirstColumnZero = true;
            break;
        }
    }
    for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[0][j] == 0) {
            matrix[0][0] = 0;
            break;
        }
    }

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
                break;
            }
        }
    }

    for (int j = 1; j < matrix[0].size(); ++j) {
        if (matrix[0][j] == 0) {
            for (int k = 1; k < matrix.size(); ++k) {
                matrix[k][j] = 0;
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][0] == 0) {
            for (int k = 1; k < matrix[0].size(); ++k) {
                matrix[i][k] = 0;
            }
        }
    }
    if (isFirstColumnZero) {
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][0] = 0;
        }
    }
}

//int main() {
//    vector<vector<int>> matrix = {
//            {0, 0, 0, 5},
//            {4, 3, 1, 4},
//            {0, 1, 1, 4},
//            {1, 2, 1, 3},
//            {0, 0, 1, 1}
//    };
//    setZeroes(matrix);
//    for (int i = 0; i < matrix.size(); ++i) {
//        for (int j = 0; j < matrix[0].size(); ++j) {
//            cout << matrix[i][j] << '\t';
//        }
//        cout << endl;
//    }
//}