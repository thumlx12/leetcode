//
// Created by maolixuan on 2017/5/20.
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

class Solution139 {
public:
    bool wordBreak(string s, unordered_set<string> &wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                string subStr = s.substr(j, i - j);
                if (wordDict.count(subStr) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        for (int i = 0; i < wordDict.size(); ++i) {
            wordSet.insert(wordDict[i]);
        }
        return wordBreak(s, wordSet);
    }
};

//int main() {
//    vector<string> dict = {"leet", "code"};
//    string s = "leetleet";
//    Solution139 *solu;
//    cout << solu->wordBreak(s, dict);
//}
