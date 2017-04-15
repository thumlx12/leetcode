//
// Created by sensetime on 4/15/17.
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

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    bool isHorizon = true;
    bool isRise = true;
    int layer = 0;
    for (int i = 0, j = 0, count = 1; count <= n * n; ++count) {
        matrix[i][j] = count;
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
                if (i < n - layer - 1) {
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
    return matrix;
}