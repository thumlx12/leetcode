//
// Created by sensetime on 5/9/17.
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


class Solution131 {
public:

    vector<vector<bool>> getPalidromeMatrix(string &s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; 0 <= j; --j) {
                dp[i][j] = true;
            }
        }
        for (int k = 1; k < s.length(); ++k) {
            for (int i = 0; i + k < s.length(); ++i) {
                int j = i + k;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp;
    }

    void
    getAllPartition(vector<vector<string>> &ans, vector<vector<bool>> &isPali,
                    vector<string> &onePartition, string &s, int current) {
        if (current >= s.length()) {
            ans.push_back(onePartition);
            return;
        }
        for (int i = 0; current + i < s.length(); ++i) {
            if (isPali[current][current + i]) {
                onePartition.push_back(s.substr(current, i + 1));
                getAllPartition(ans, isPali, onePartition, s, current + i + 1);
                onePartition.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> isPali = getPalidromeMatrix(s);
        vector<vector<string>> ans;
        vector<string> onePartition;
        getAllPartition(ans, isPali, onePartition, s, 0);
        return ans;
    }
};

//int main() {
//    Solution131 *solu = new Solution131();
//    vector<vector<string>> allPartition = solu->partition("abbab");
//    for (int i = 0; i < allPartition.size(); ++i) {
//        for (int j = 0; j < allPartition[i].size(); ++j) {
//            cout << allPartition[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}