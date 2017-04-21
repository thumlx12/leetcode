//
// Created by sensetime on 4/21/17.
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

void searchWord_DFS(vector<vector<char>> &board, string &word, bool &ans,
                    vector<vector<bool>> &isUsedChar,
                    int current, int pos_x, int pos_y) {
    isUsedChar[pos_x][pos_y] = true;
    if (board[pos_x][pos_y] != word[current]) {
        isUsedChar[pos_x][pos_y] = false;
        return;
    }
    if (current >= word.length() - 1) {
        ans = true;
        return;
    }
    //up
    if (pos_x - 1 >= 0 && !isUsedChar[pos_x - 1][pos_y]) {
        searchWord_DFS(board, word, ans, isUsedChar, current + 1, pos_x - 1, pos_y);
        if (ans) {
            return;
        }
    }
    //left
    if (pos_y - 1 >= 0 && !isUsedChar[pos_x][pos_y - 1]) {
        searchWord_DFS(board, word, ans, isUsedChar, current + 1, pos_x, pos_y - 1);
        if (ans) {
            return;
        }
    }
    //down
    if (pos_x + 1 < board.size() && !isUsedChar[pos_x + 1][pos_y]) {
        searchWord_DFS(board, word, ans, isUsedChar, current + 1, pos_x + 1, pos_y);
        if (ans) {
            return;
        }
    }
    //right
    if (pos_y + 1 < board[0].size() && !isUsedChar[pos_x][pos_y + 1]) {
        searchWord_DFS(board, word, ans, isUsedChar, current + 1, pos_x, pos_y + 1);
        if (ans) {
            return;
        }
    }
    isUsedChar[pos_x][pos_y] = false;
}

bool exist(vector<vector<char>> &board, string word) {
    const int m = board.size();
    if (m <= 0) {
        return false;
    }
    const int n = board[0].size();
    if (n <= 0) {
        return false;
    }
    bool ifExist = false;
    vector<vector<bool>> isUsedChar(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            searchWord_DFS(board, word, ifExist, isUsedChar, 0, i, j);
            if (ifExist) {
                return true;
            }
        }
    }
    return false;
}

//int main() {
//    vector<vector<char>> board{
//            {'A', 'B', 'C', 'E'},
//            {'S', 'F', 'C', 'S'},
//            {'A', 'D', 'E', 'E'}
//    };
//    string word = "ABCB";
//    cout << exist(board, word);
//}