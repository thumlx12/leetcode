#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> routes;

    vector<vector<string>> findLadders(string &begin, string &end, unordered_set<string> &dict) {
        dict.insert(begin);
        dict.insert(end);

        unordered_map<string, vector<string>> prevs_map;
        vector<string> prev;
        for (unordered_set<string>::const_iterator iter = dict.begin(); iter != dict.end(); ++iter) {
            prevs_map[*iter] = prev;
        }
        vector<unordered_set<string>> layerTwo(2);
        bool current = false;
        layerTwo[current].insert(begin);
        while (!prevs_map[end].size()) {
            current = !current;
            layerTwo[current].clear();
            for (unordered_set<string>::const_iterator iter = layerTwo[!current].begin();
                 iter != layerTwo[!current].end(); ++iter) {
                dict.erase(*iter);
            }
            for (unordered_set<string>::const_iterator iter = layerTwo[!current].begin();
                 iter != layerTwo[!current].end(); ++iter) {
                string currentWord = *iter;
                for (int i = 0; i < currentWord.length(); ++i) {
                    char oldChar = currentWord[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (oldChar == c) {
                            continue;
                        }
                        currentWord[i] = c;
                        if (dict.find(currentWord) != dict.end()) {
                            prevs_map[currentWord].push_back(*iter);
                            layerTwo[current].insert(currentWord);
                        }
                    }
                    currentWord[i] = oldChar;
                }
            }
            if (layerTwo[current].size() <= 0) {
                return routes;
            }
        }
        vector<string> route;
        route.push_back(end);
        findRoutesDFS(end, prevs_map, route, routes);
        return routes;
    }

    void findRoutesDFS(string &str, unordered_map<string, vector<string>> &prevs_map,
                       vector<string> &oneRoute, vector<vector<string>> &routes) {
        if (prevs_map[str].size() <= 0) {
            vector<string> trueRoute = oneRoute;
            reverse(trueRoute.begin(), trueRoute.end());
            routes.push_back(trueRoute);
            return;
        }
        for (int i = 0; i < prevs_map[str].size(); ++i) {
            oneRoute.push_back(prevs_map[str][i]);
            findRoutesDFS(prevs_map[str][i], prevs_map, oneRoute, routes);
            oneRoute.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> dict;
        for (int i = 0; i < wordList.size(); ++i) {
            dict.insert(wordList[i]);
        }
        if (dict.find(endWord) != dict.end()) {
            return findLadders(beginWord, endWord, dict);
        } else {
            return routes;
        }
    }
};

// int main() {
//     vector<string> list = {"rex", "ted", "tax", "tex"};
//     Solution *solu = new Solution();
//     vector<vector<string> > pathes = solu->findLadders("red", "tax", list);
//     for (int i = 0; i < pathes.size(); ++i) {
//         for (int j = 0; j < pathes[i].size(); ++j) {
//             cout << pathes[i][j] << "\t";
//         }
//         cout << endl;
//     }
// }
