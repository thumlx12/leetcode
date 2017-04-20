//
// Created by sensetime on 4/20/17.
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

string minWindow(string s, string t) {
    if (s.length() <= 0) {
        return "";
    }
    vector<int> leftMatchTimes(256, 0);
    for (int i = 0; i < t.length(); ++i) {
        leftMatchTimes[t[i]]++;
    }
    bool isContain = false;
    int leftChars = t.length();
    int min_left = 0;
    int min_right = s.length() - 1;
    // init
    if (leftMatchTimes[s[0]] > 0) {
        leftChars--;
    }
    leftMatchTimes[s[0]]--;

    for (int left = 0, right = 0; right < s.length();) {
        if (leftChars == 0) {
            isContain = true;
            if (right - left + 1 < min_right - min_left + 1) {
                min_left = left;
                min_right = right;
            }
            left++;
            if (leftMatchTimes[s[left - 1]] >= 0) {
                leftChars++;
            }
            leftMatchTimes[s[left - 1]]++;
        } else {
            right++;
            if (leftMatchTimes[s[right]] > 0) {
                leftChars--;
            }
            leftMatchTimes[s[right]]--;
        }
    }
    if (!isContain) {
        return "";
    } else {
        return s.substr(min_left, min_right - min_left + 1);
    }
}

//int main() {
//    string S = "A";
//    string T = "A";
//    cout << minWindow(S, T);
//}
