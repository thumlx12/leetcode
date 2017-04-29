//
// Created by sensetime on 4/29/17.
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

//void inorderTraversal_recursive2(TreeNode *root, vector<int> &ret) {
//    if (!root) {
//        return;
//    }
//    inorderTraversal_recursive2(root->left, ret);
//    ret.push_back(root->val);
//    inorderTraversal_recursive2(root->right, ret);
//}

bool judgeBST(TreeNode *root, TreeNode *maxNode, TreeNode *minNode) {
    if (!root) {
        return true;
    }
    if ((minNode && root->val <= minNode->val) || (maxNode && maxNode->val <= root->val)) {
        return false;
    }
    return judgeBST(root->left, root, minNode) && (judgeBST(root->right, maxNode, root));
}

bool isValidBST(TreeNode *root) {
    return judgeBST(root, NULL, NULL);
}

//int main() {
//    TreeNode *n1 = new TreeNode(5);
//    TreeNode *n2 = new TreeNode(3);
//    TreeNode *n3 = new TreeNode(12);
//    TreeNode *n4 = new TreeNode(9);
//    n1->right = n4;
//    n1->left = n2;
//    n2->right = n3;
//    cout << isValidBST(n1);
//}
