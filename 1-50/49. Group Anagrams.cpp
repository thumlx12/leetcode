//
// Created by sensetime on 4/11/17.
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

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagrams;
    unordered_map<string, vector<string>>::iterator it;
    for (int i = 0; i < strs.size(); ++i) {
        string key = strs[i];
        sort(key.begin(), key.end());
        if ((it = anagrams.find(key)) != anagrams.end()) {
            it->second.push_back(strs[i]);
        } else {
            vector<string> set = {strs[i]};
            anagrams.insert(make_pair(key, set));
        }
    }
    vector<vector<string>> result;
    for (it = anagrams.begin(); it != anagrams.end(); ++it) {
        result.push_back(it->second);
    }
    return result;
}

//int main() {
//    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//    vector<vector<string>> result = groupAnagrams(strs);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << ",";
//        }
//        cout << endl;
//    }
//}
