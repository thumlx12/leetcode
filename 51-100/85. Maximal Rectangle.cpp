//
// Created by sensetime on 4/25/17.
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

int maximalRectangle_n3(vector<vector<char>> &matrix) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0) {
        return 0;
    }
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> h(m, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        if (matrix[m - 1][j] == '1') {
            h[m - 1][j] = 1;
        }
    }
    for (int i = m - 2; 0 <= i; --i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                h[i][j] = h[i + 1][j] + 1;
            }
        }
    }
    int maxRect = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int maxHeight = h[i][j];
            maxRect = max(maxRect, h[i][j]);
            for (int w = 1; j + w < n; ++w) {
                maxHeight = min(maxHeight, h[i][j + w]);
                maxRect = max(maxRect, (w + 1) * maxHeight);
            }
        }
    }
    return maxRect;
}

int largestRectangleArea_1(vector<int> &heights) {
    if (heights.size() <= 0) {
        return 0;
    }
    stack<int> bar;
    heights.push_back(-1);
    int maxArea = -1;
    int h, w;
    for (int i = 0; i < heights.size(); ++i) {
        if (!bar.empty() && heights[i] <= heights[bar.top()]) {
            while (!bar.empty() && heights[i] <= heights[bar.top()]) {
                h = heights[bar.top()];
                bar.pop();
                w = bar.empty() ? i : (i - bar.top() - 1);
                maxArea = max(maxArea, h * w);
            }
        }
        bar.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0) {
        return 0;
    }
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> h(m, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        if (matrix[m - 1][j] == '1') {
            h[m - 1][j] = 1;
        }
    }
    for (int i = m - 2; 0 <= i; --i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                h[i][j] = h[i + 1][j] + 1;
            }
        }
    }
    int maxRect = -1;
    for (int i = 0; i < m; ++i) {
        maxRect = max(maxRect, largestRectangleArea_1(h[i]));
    }
    return maxRect;
}


//int main() {
//    vector<vector<char>> matrix = {
//            {'1', '0', '1', '0', '0'},
//            {'1', '0', '1', '1', '1'},
//            {'1', '1', '1', '1', '1'},
//            {'1', '0', '0', '1', '0'}
//    };
//    cout << maximalRectangle(matrix);
//}