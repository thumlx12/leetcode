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

bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return (sum == root->val);
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
