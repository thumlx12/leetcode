//
// Created by sensetime on 4/27/17.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> getUniqueTrees(int start, int end) {
    vector<TreeNode *> ret;
    if (start > end) {
        ret.push_back(NULL);
        return ret;
    }
    for (int i = start; i <= end; ++i) {
        vector<TreeNode *> leftTrees = getUniqueTrees(start, i - 1);
        vector<TreeNode *> rightTrees = getUniqueTrees(i + 1, end);
        for (int j = 0; j < leftTrees.size(); ++j) {
            for (int k = 0; k < rightTrees.size(); ++k) {
                TreeNode *root = new TreeNode(i);
                ret.push_back(root);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
            }
        }
    }
    return ret;
}

vector<TreeNode *> generateTrees(int n) {
    if (n <= 0) {
        return vector<TreeNode *>();
    }
    return getUniqueTrees(1, n);
}

void printTree(TreeNode *root) {
    if (!root) {
        printf("NULL\t");
        return;
    }
    printf("%d\t", root->val);
    printTree(root->left);
    printTree(root->right);
}


//int main() {
//    vector<TreeNode *> ret = generateTrees(5);
//    for (int i = 0; i < ret.size(); ++i) {
//        printTree(ret[i]);
//        printf("\n");
//    }
//}
