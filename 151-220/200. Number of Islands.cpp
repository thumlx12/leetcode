//
// Created by maolixuan on 2017/6/6.
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
#include <map>
#include <bitset>

using namespace std;

class Solution200 {
public:

    int m;
    int n;

    void visitIsland(vector<vector<char>> &grid, vector<vector<bool>> &isVisited, int x, int y) {
        if (isVisited[x][y] || grid[x][y] == '0') {
            return;
        }
        isVisited[x][y] = true;
        if (x + 1 < m) {//down
            visitIsland(grid, isVisited, x + 1, y);
        }
        if (y + 1 < n) {//right
            visitIsland(grid, isVisited, x, y + 1);
        }
        if (0 <= x - 1) {//up
            visitIsland(grid, isVisited, x - 1, y);
        }
        if (0 <= y - 1) {//left
            visitIsland(grid, isVisited, x, y - 1);
        }

    }

    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        if (m <= 0) {
            return 0;
        }
        n = grid[0].size();

        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        int islandNum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!isVisited[i][j] && grid[i][j] == '1') {
                    islandNum++;
                    visitIsland(grid, isVisited, i, j);
                }
            }
        }
        return islandNum;
    }
};
