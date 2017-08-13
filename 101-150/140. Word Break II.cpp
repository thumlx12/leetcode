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

class Solution140 {
public:

    void
    makeSentences(vector<string> &sentences, unordered_map<int, vector<string>> &start2end,
                  int &end, int start, string current) {
        if (start >= end) {
            current.pop_back();
            sentences.push_back(current);
            return;
        }
        for (int i = 0; i < start2end[start].size(); ++i) {
            makeSentences(sentences, start2end, end,
                          start + start2end[start][i].length(),
                          current + start2end[start][i] + " ");
        }
    }

    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        vector<string> sentences;
        vector<bool> dp(s.length() + 1, false);
        unordered_map<int, vector<string>> start2end;
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                string subStr = s.substr(j, i - j);
                if (dp[j] && wordDict.count(subStr)) {
                    dp[i] = true;
                    start2end[j].push_back(subStr);
                }
            }
        }
        if (!dp[s.length()]) {
            return sentences;
        }
        int end = s.length();
        makeSentences(sentences, start2end, end, 0, "");
        return sentences;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        for (int i = 0; i < wordDict.size(); ++i) {
            wordSet.insert(wordDict[i]);
        }
        return wordBreak(s, wordSet);
    }
};

//int main() {
//    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
//    string s = "catsanddog";
//    Solution140 *solu;
//    vector<string> ret = solu->wordBreak(s, dict);
//    for (int i = 0; i < ret.size(); ++i) {
//        cout << ret[i] << "\n";
//    }
//}
