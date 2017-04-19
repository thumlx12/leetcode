//
// Created by sensetime on 4/11/17.
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
backtrackingSolution(vector<vector<string>> &result, int &n, vector<string> &oneSolution,
                     vector<bool> &column, vector<bool> &crossline_left, vector<bool> &crossline_right, int current) {
    if (current >= n) {
        result.push_back(oneSolution);
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

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> oneSolution(n, string(n, '.'));
    vector<bool> column(n, false);
    vector<bool> crossline_left(2 * n - 1, false);
    vector<bool> crossline_right(2 * n - 1, false);
    backtrackingSolution(result, n, oneSolution, column, crossline_left, crossline_right, 0);
    return result;
}

//int main() {
//    vector<vector<string>> result = solveNQueens(8);
//    cout << result.size() << endl << endl;
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << endl;
//        }
//        cout << endl;
//    }
//}