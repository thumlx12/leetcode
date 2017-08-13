//
// Created by sensetime on 5/9/17.
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
#include <queue>
#include <unordered_set>

using namespace std;

void captureDFS_out2in(vector<vector<char>> &board, int x, int y) {
    if (board[x][y] == 'O') {
        board[x][y] = 'E';
        if (x - 1 > 0) {
            captureDFS_out2in(board, x - 1, y);
        }
        if (x + 1 < board.size()) {
            captureDFS_out2in(board, x + 1, y);
        }
        if (y - 1 > 0) {
            captureDFS_out2in(board, x, y - 1);
        }
        if (y + 1 < board[0].size()) {
            captureDFS_out2in(board, x, y + 1);
        }
    }
}

void solve(vector<vector<char>> &board) {
    if (board.size() <= 2) {
        return;
    }
    if (board[0].size() <= 2) {
        return;
    }
    int m = board.size();
    int n = board[0].size();
    for (int j = 0; j < n; ++j) {
        if (board[0][j] == 'O') {
            captureDFS_out2in(board, 0, j);
        }
    }
    for (int j = 0; j < n; ++j) {
        if (board[m - 1][j] == 'O') {
            captureDFS_out2in(board, m - 1, j);
        }
    }
    for (int i = 1; i < m - 1; ++i) {
        if (board[i][0] == 'O') {
            captureDFS_out2in(board, i, 0);
        }
    }
    for (int i = 1; i < m - 1; ++i) {
        if (board[i][n - 1] == 'O') {
            captureDFS_out2in(board, i, n - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'E') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

//int main() {
//    vector<vector<char>> board = {
//            {'O', 'O', 'X', 'O', 'X'},
//            {'O', 'X', 'O', 'X', 'O'},
//            {'X', 'O', 'X', 'O', 'X'},
//            {'O', 'O', 'X', 'X', 'X'}
//    };
//
//    solve(board);
//    for (int i = 0; i < board.size(); ++i) {
//        for (int j = 0; j < (*board.begin()).size(); ++j) {
//            cout << board[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}
