//
// Created by sensetime on 4/10/17.
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

void rotate4(vector<vector<int>> &matrix, int i, int j, int n) {
    int tmp[4];
    int start_i = i;
    int start_j = j;
    int next_x;
    int next_y;
    for (int count = 0; count < 4; ++count) {
        tmp[(count + 1) % 4] = matrix[i][j];
        next_x = j;
        next_y = n - i - 1;
        i = next_x;
        j = next_y;
    }
    i = start_i;
    j = start_j;
    for (int count = 0; count < 4; ++count) {
        matrix[i][j] = tmp[count];
        next_x = j;
        next_y = n - i - 1;
        i = next_x;
        j = next_y;
    }
}

void rotate(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; ++j) {
            rotate4(matrix, i, j, n);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
    rotate(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
