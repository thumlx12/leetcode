//
// Created by sensetime on 4/1/17.
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

bool row[9][9];
bool col[9][9];
bool square[9][9];


bool dfsSolveSudoku(vector<vector<char>> &board, int pos) {
    if (pos >= 81) {
        return true;
    }
    int x = pos / 9;
    int y = pos % 9;
    if (board[x][y] != '.') {
        return dfsSolveSudoku(board, pos + 1);
    }
    int rect_coor = 3 * (x / 3) + y / 3;
    for (int count = 0; count < 9; ++count) {
        if (row[x][count] || col[y][count] || square[rect_coor][count]) {
            continue;
        }
        row[x][count] = col[y][count] = square[rect_coor][count] = true;
        if (dfsSolveSudoku(board, pos + 1)) {
            board[x][y] = count + 49;
            return true;
        }
        row[x][count] = col[y][count] = square[rect_coor][count] = false;
    }
    return false;

}

void solveSudoku(vector<vector<char>> &board) {
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    memset(square, 0, sizeof(square));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - 49;
                row[i][num] = 1;
                col[j][num] = 1;
                square[3 * (i / 3) + j / 3][num] = 1;
            }
        }
    }
    dfsSolveSudoku(board, 0);
}
