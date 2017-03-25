//
// Created by sensetime on 3/25/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

const vector<string> digitLetterTable = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations_aux(vector<string> &res, string &digits, string combination, int st) {
    if (st >= digits.size()) {
        res.push_back(combination);
        return;
    }
    int index = digits.at(st) - 48;
    string digitLetters = digitLetterTable[index];
    for (int i = 0; i < digitLetters.length(); ++i) {
        combination += digitLetters.at(i);
        letterCombinations_aux(res, digits, combination, st + 1);
        combination.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.length() > 0) {
        string oriStr = "";
        letterCombinations_aux(res, digits, oriStr, 0);
    }
    return res;
}

int main() {
    string str = "234";
    vector<string> res = letterCombinations(str);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}