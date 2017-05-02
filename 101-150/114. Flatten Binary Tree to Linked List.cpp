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

TreeNode *flattenBT(TreeNode *root) {
    if (!root) {
        return NULL;
    }
    TreeNode *leftEnd = flattenBT(root->left);
    TreeNode *rightEnd = flattenBT(root->right);
    if (root->left) {
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        leftEnd->right = tmp;
    }
    if (rightEnd) {
        return rightEnd;
    }
    if (leftEnd) {
        return leftEnd;
    }
    return root;
}

void flatten(TreeNode *root) {
    if (!root) {
        return;
    }
    for (; root; root = root->right) {
        if (root->left) {
            TreeNode *LT = root->left;
            while (LT->right)
                LT = LT->right;
            LT->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
}

//int main() {
//    TreeNode *n1 = new TreeNode(3);
//    TreeNode *n2 = new TreeNode(9);
//    TreeNode *n3 = new TreeNode(20);
//    TreeNode *n4 = new TreeNode(8);
//    TreeNode *n5 = new TreeNode(10);
//    TreeNode *n6 = new TreeNode(15);
//    TreeNode *n7 = new TreeNode(7);
//    TreeNode *n8 = new TreeNode(17);
//    TreeNode *n9 = new TreeNode(19);
//    TreeNode *n10 = new TreeNode(21);
//    TreeNode *n11 = new TreeNode(20);
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;
//    n4->left = n8;
//    n5->left = n9;
//    n7->left = n10;
//    n7->right = n11;
//    flatten(n1);
//    cout << endl;
//}