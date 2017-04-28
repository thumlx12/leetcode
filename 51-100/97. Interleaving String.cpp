//
// Created by sensetime on 4/28/17.
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

bool isInterleave(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) {
        return false;
    }
    vector<vector<bool>> f(2, vector<bool>(s2.length() + 1, false));
    f[0][0] = true;
    for (int j = 1; j <= s2.length(); ++j) {
        f[0][j] = f[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    bool current = false;
    for (int i = 1; i <= s1.length(); ++i) {
        current = !current;
        f[current][0] = f[!current][0] && (s1[i - 1] == s3[i - 1]);
        for (int j = 1; j <= s2.length(); ++j) {
            f[current][j] = false;
            if (s3[i + j - 1] == s1[i - 1]) {
                f[current][j] = f[!current][j];
            }
            if (s3[i + j - 1] == s2[j - 1]) {
                f[current][j] = f[current][j] || f[current][j - 1];
            }
        }
    }
    return f[current][s2.length()];
}

//int main() {
//    string s1 = "aabc";
//    string s2 = "abad";
//    string s3 = "aabadabc";
//    cout << isInterleave(s1, s2, s3) << endl;
//}
