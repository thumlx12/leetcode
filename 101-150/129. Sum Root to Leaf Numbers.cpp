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
#include <bitset>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getSumNumber(int &ans, int current, TreeNode *root) {
    if (!root->left && !root->right) {
        ans += 10 * current + root->val;
        return;
    }
    current = 10 * current + root->val;
    if (root->left) {
        getSumNumber(ans, current, root->left);
    }
    if (root->right) {
        getSumNumber(ans, current, root->right);
    }
}

int sumNumbers(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int ans = 0;
    getSumNumber(ans, 0, root);
    return ans;
}