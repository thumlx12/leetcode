//
// Created by sensetime on 5/2/17.
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findAllSuitablePaths(TreeNode *root, int sum, vector<vector<int>> &paths, vector<int> &current) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        if (sum == root->val) {
            current.push_back(root->val);
            paths.push_back(current);
            current.pop_back();
        }
        return;
    }
    current.push_back(root->val);
    findAllSuitablePaths(root->left, sum - root->val, paths, current);
    findAllSuitablePaths(root->right, sum - root->val, paths, current);
    current.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    vector<int> current;
    findAllSuitablePaths(root, sum, res, current);
    return res;
}