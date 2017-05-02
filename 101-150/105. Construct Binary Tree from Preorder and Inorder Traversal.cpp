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

TreeNode *reconstructTree(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd) {
    if (inEnd - inStart < 1) {
        if (inStart == inEnd) {
            return (new TreeNode(inorder[inStart]));
        } else {
            return NULL;
        }
    }
    TreeNode *root = new TreeNode(preorder[preStart]);
    int root_idx = inStart;
    for (; root_idx <= inEnd; ++root_idx) {
        if (inorder[root_idx] == preorder[preStart]) {
            break;
        }
    }
    root->left = reconstructTree(preorder, inorder, preStart + 1, inStart, root_idx - 1);
    root->right = reconstructTree(preorder, inorder, preStart + (root_idx - inStart) + 1, root_idx + 1, inEnd);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() <= 0 || inorder.size() <= 0 || preorder.size() != inorder.size()) {
        return NULL;
    }
    return reconstructTree(preorder, inorder, 0, 0, preorder.size() - 1);
}

//int main() {
//    vector<int> preOrder = {1, 2, 3};
//    vector<int> inOrder = {3, 2, 1};
//    TreeNode *BTroot = buildTree(preOrder, inOrder);
//    cout << endl;
//}
