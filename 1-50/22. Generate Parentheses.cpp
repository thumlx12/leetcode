//
// Created by LIXUAN MAO on 2017/3/26.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>

using namespace std;

void generateParenthesis_aux(vector<string> &res, const int &total, string combination,
                             int lst, int rst, int PStack) {
    if (lst >= total && rst >= total) {
        res.push_back(combination);
        return;
    }
    if (lst < total) {
        combination += "(";
        lst++;PStack++;
        generateParenthesis_aux(res, total, combination, lst, rst, PStack);
        lst--;PStack--;
        combination.pop_back();
    }
    if (PStack > 0) {
        combination += ")";
        rst++;PStack--;
        generateParenthesis_aux(res, total, combination, lst, rst, PStack);
        rst--;PStack++;
        combination.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesis_aux(result, n, "", 0, 0, 0);
    return result;
}
//
//int main() {
//    vector<string> PResult = generateParenthesis(3);
//    for (int i = 0; i < PResult.size(); ++i) {
//        cout << PResult[i] << endl;
//    }
//}
