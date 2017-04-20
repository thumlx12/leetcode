//
// Created by sensetime on 4/19/17.
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

int getNthElement(vector<vector<int>> &matrix, int num) {
    int x = num / matrix[0].size();
    int y = num % matrix[0].size();
    return matrix[x][y];
}

bool binaryMatrixSearch(vector<vector<int>> &matrix, int lo, int hi, int &target) {
    if (hi - lo < 1) {
        if (getNthElement(matrix, lo) == target) {
            return true;
        } else {
            return false;
        }
    }
    int mi_index = (hi + lo) / 2;
    int mi = getNthElement(matrix, mi_index);
    if (target < mi) {
        return binaryMatrixSearch(matrix, lo, mi_index - 1, target);
    } else if (mi < target) {
        return binaryMatrixSearch(matrix, mi_index + 1, hi, target);
    } else {
        return true;
    }

}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() <= 0) {
        return false;
    }
    if (matrix[0].size() <= 0) {
        return false;
    }
    const int m = matrix.size();
    const int n = matrix[0].size();
    if (m <= 0 || n <= 0) {
        return false;
    }
    return binaryMatrixSearch(matrix, 0, m * n - 1, target);
}

//int main() {
//    vector<vector<int>> matrix = {
//            {1, 1}
//    };
//    cout << searchMatrix(matrix, 1);
//}