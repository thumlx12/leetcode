//
// Created by sensetime on 4/25/17.
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

bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    if (s1 == s2) {
        return true;
    }
    vector<int> isUsed(255, 0);
    for (int i = 0; i < s1.length(); ++i) {
        isUsed[s1[i]]++;
        isUsed[s2[i]]--;
    }
    for (int i = 0; i < isUsed.size(); ++i) {
        if (isUsed[i] != 0) {
            return false;
        }
    }
    for (int k = 1; k < s1.size(); ++k) {
        string s11 = s1.substr(0, k);
        string s12 = s1.substr(k);
        string s21 = s2.substr(0, k);
        string s22 = s2.substr(k);
        bool noExchange = isScramble(s11, s21) && isScramble(s12, s22);
        if (noExchange) {
            return true;
        }
        s21 = s2.substr(s2.length() - k);
        s22 = s2.substr(0, s2.length() - k);
        bool Exchange = isScramble(s11, s21) && isScramble(s12, s22);
        if (Exchange) {
            return true;
        }
    }
    return false;
}
