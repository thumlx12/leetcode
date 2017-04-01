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

bool isValidSudoku_concise(vector<vector<char>>& board) {
    int col[9][9] = {0}, row[9][9] = {0}, rec[9][9] = {0};
    for(int i = 0; i < 9; ++ i) {
        for(int j = 0; j < 9; ++ j) {
            if(board[i][j] != '.') {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(col[i][num] || row[j][num] || rec[k][num])
                    return false;

                col[i][num] = row[j][num] = rec[k][num] = 1;
            }
        }
    }

    return true;
}

void clearVec(vector<bool> &v) {
    for (int i = 0; i < v.size(); ++i) {
        v[i] = false;
    }
}

bool isValidSudoku(vector<string> &board) {
    bool isValid = true;
    vector<bool> one2nine(9, false);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                if (!one2nine[board[i][j] - 49]) {
                    one2nine[board[i][j] - 49] = true;
                } else {
                    isValid = false;
                    goto goback;
                }
            }
        }
        clearVec(one2nine);
    }
    for (int t = 0; t < 9; ++t) {
        for (int p = 0; p < 9; ++p) {
            if (board[p][t] != '.') {
                if (!one2nine[board[p][t] - 49]) {
                    one2nine[board[p][t] - 49] = true;
                } else {
                    isValid = false;
                    goto goback;
                }
            }
        }
        clearVec(one2nine);
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            vector<bool> one2nine(9, false);
            for (int k = i, kc = 0; kc < 3; ++kc) {
                for (int t = j, tc = 0; tc < 3; ++tc) {
                    if (board[k + kc][t + tc] != '.') {
                        if (!one2nine[board[k + kc][t + tc] - 49]) {
                            one2nine[board[k + kc][t + tc] - 49] = true;
                        } else {
                            isValid = false;
                            goto goback;
                        }
                    }
                }
            }
            clearVec(one2nine);
        }
    }

    goback:
    return isValid;
}

//int main() {
//    vector<string> board = {
//            ".87654321",
//            "2........",
//            "3........",
//            "4........",
//            "5........",
//            "6........",
//            "7........",
//            "8........",
//            "9........"
//    };
//
//    cout << isValidSudoku(board);
//}