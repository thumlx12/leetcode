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

void inorderTraversal_recursive(TreeNode *root, vector<int> &ret) {
    if (!root) {
        return;
    }
    inorderTraversal_recursive(root->left, ret);
    ret.push_back(root->val);
    inorderTraversal_recursive(root->right, ret);
}


void inorderTraversal_iterative(TreeNode *root, vector<int> &ret) {
    stack<TreeNode *> stack_helper;
    while (!stack_helper.empty() || root) {
        while (root) {
            stack_helper.push(root);
            root = root->left;
        }
        root = stack_helper.top();
        ret.push_back(root->val);
        stack_helper.pop();
        root = root->right;
    }
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    inorderTraversal_iterative(root, ret);
    return ret;
}

//int main() {
//    TreeNode *n1 = new TreeNode(1);
//    TreeNode *n2 = new TreeNode(2);
//    TreeNode *n3 = new TreeNode(3);
//    n1->right = n2;
//    n2->left = n3;
//    vector<int> inorder = inorderTraversal(n1);
//    for (int i = 0; i < inorder.size(); ++i) {
//        cout << inorder[i] << "\t";
//    }
//}