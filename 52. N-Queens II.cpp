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

void
backtrackingSolution(int &result, int &n, vector<string> &oneSolution,
                     vector<bool> &column, vector<bool> &crossline_left, vector<bool> &crossline_right, int current) {
    if (current >= n) {
        result++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!column[i] && !crossline_left[current + i] && !crossline_right[current + n - i - 1]) {
            oneSolution[current][i] = 'Q';
            column[i] = true;
            crossline_left[current + i] = true;
            crossline_right[current + n - i - 1] = true;

            backtrackingSolution(result, n, oneSolution, column, crossline_left, crossline_right, current + 1);

            oneSolution[current][i] = '.';
            column[i] = false;
            crossline_left[current + i] = false;
            crossline_right[current + n - i - 1] = false;
        }
    }

}

int totalNQueens(int n) {
    int result = 0;
    vector<string> oneSolution(n, string(n, '.'));
    vector<bool> column(n, false);
    vector<bool> crossline_left(2 * n - 1, false);
    vector<bool> crossline_right(2 * n - 1, false);
    backtrackingSolution(result, n, oneSolution, column, crossline_left, crossline_right, 0);
    return result;
}
