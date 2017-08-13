//
// Created by sensetime on 5/6/17.
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

int wordDistance(string &s1, string &s2) {
    if (s1.length() != s1.length()) {
        return -1;
    }
    int dis = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            dis++;
        }
    }
    return dis;
}

int ladderBFS(string &beginWord, string &endWord, unordered_set<string> &wordList) {
    const int n = beginWord.length();
    queue<string> BFS;
    BFS.push(beginWord);
    for (int minSteps = 2; !BFS.empty(); ++minSteps) {
        int currentSize = BFS.size();
        for (int t = 0; t < currentSize; ++t) {
            string curStr = BFS.front();
            BFS.pop();
            for (int k = 0; k < n; ++k) {
                char oldChar = curStr[k];
                for (char p = 'a'; p <= 'z'; ++p) {
                    if (p == oldChar) {
                        continue;
                    }
                    curStr[k] = p;
                    if (curStr == endWord) {
                        return minSteps;
                    }
                    if (wordList.find(curStr) != wordList.end()) {
                        BFS.push(curStr);
                        wordList.erase(curStr);
                    }
                }
                curStr[k] = oldChar;
            }
        }
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict;
    for (int i = 0; i < wordList.size(); ++i) {
        dict.insert(wordList[i]);
    }
    if (dict.find(endWord) == dict.end()) {
        return 0;
    }
    return ladderBFS(beginWord, endWord, dict);
}