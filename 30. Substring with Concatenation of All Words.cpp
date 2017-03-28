//
// Created by sensetime on 3/28/17.
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

using namespace std;

vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> result;
    if (s.length() <= 0 && words.size() <= 0) {
        return result;
    }
    int wl = words.front().length();
    int lengthLeft = s.length() - wl * words.size();
    unordered_map<string, int> wordDic;
    for (int i = 0; i < words.size(); ++i) ++wordDic[words[i]];
    unordered_map<string, int> usedWordDic;

    for (int i = 0; i <= lengthLeft; ++i) {
        bool isMatch = false;
        usedWordDic.clear();
        for (int j = 0; j < words.size(); ++j) {
            string pattern = s.substr(i + j * wl, wl);
            if (!wordDic[pattern] || ++usedWordDic[pattern] > wordDic[pattern]) {
                isMatch = false;
                break;
            } else {
                isMatch = true;
            }
        }
        if (isMatch) {
            result.push_back(i);
        }
    }
    return result;
}


void printEach(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

//int main() {
//    string s1 = "barfoothefoobarmant";
//    vector<string> w1 = {"foo", "bar"};
//    vector<int> index1 = findSubstring(s1, w1);
//    printEach(index1);
//}
