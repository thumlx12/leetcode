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
#include <bits/unordered_set.h>

using namespace std;

class Solution126 {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        pathes.clear();
        dict.insert(start);
        dict.insert(end);
        /*initialization*/
        vector<string> prev;
        unordered_map<string, vector<string> > traces;
        for (unordered_set<string>::const_iterator citr = dict.begin(); citr != dict.end(); citr++) {
            traces[*citr] = prev;
        }

        vector<unordered_set<string> > layers(2);
        bool cur = false;
        layers[cur].insert(start);
        while (true) {
            cur = !cur;
            for (unordered_set<string>::const_iterator citr = layers[!cur].begin(); citr != layers[!cur].end(); citr++)
                dict.erase(*citr);
            layers[cur].clear();
            for (unordered_set<string>::const_iterator citr = layers[!cur].begin();
                 citr != layers[!cur].end(); citr++) {
                for (int n = 0; n < (*citr).size(); n++) {
                    string word = *citr;
                    char oldChar = (*citr)[n];
                    for (char p = 'a'; p <= 'z'; ++p) {
                        if (oldChar == p) {
                            continue;
                        }
                        word[n] = p;
                        if (dict.find(word) != dict.end()) {
                            traces[word].push_back(*citr);
                            layers[cur].insert(word);
                        }
                        word[n] = oldChar;
                    }
                }
            }
            if (layers[cur].size() == 0)
                return pathes;
            if (layers[cur].count(end))
                break;
        }
        vector<string> path;
        buildPath(traces, path, end);

        return pathes;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> dict;
        for (int i = 0; i < wordList.size(); ++i) {
            dict.insert(wordList[i]);
        }
        if (dict.find(endWord) != dict.end()) {
            return findLadders(beginWord, endWord, dict);
        } else {
            return pathes;
        }
    }

private:
    void buildPath(unordered_map<string, vector<string> > &traces,
                   vector<string> &path, const string &word) {
        if (traces[word].size() == 0) {
            path.push_back(word);
            vector<string> curPath = path;
            reverse(curPath.begin(), curPath.end());
            pathes.push_back(curPath);
            path.pop_back();
            return;
        }

        const vector<string> &prevs = traces[word];
        path.push_back(word);
        for (vector<string>::const_iterator citr = prevs.begin();
             citr != prevs.end(); citr++) {
            buildPath(traces, path, *citr);
        }
        path.pop_back();
    }

    vector<vector<string> > pathes;
};
//
//int main() {
//    vector<string> list = {"rex", "ted", "tax", "tex"};
//    Solution126 *solu = new Solution126();
//    vector<vector<string> > pathes = solu->findLadders("red", "tax", list);
//    for (int i = 0; i < pathes.size(); ++i) {
//        for (int j = 0; j < pathes[i].size(); ++j) {
//            cout << pathes[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}

