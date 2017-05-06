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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxToRoot(TreeNode *root, int &maxSum) {
    if (!root) {
        return 0;
    }
    int LT = maxToRoot(root->left, maxSum);
    int RT = maxToRoot(root->right, maxSum);
    LT = max(LT, 0);
    RT = max(RT, 0);
    maxSum = max(maxSum, LT + RT + root->val);
    return root->val += max(LT, RT);
}

int maxPathSum(TreeNode *root) {
    int maxSum = INT_MIN;
    maxToRoot(root, maxSum);
    return maxSum;
}
